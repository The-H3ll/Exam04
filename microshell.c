//
// Created by Mouaad Labhairi on 12/16/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int	fd[2];

typedef struct microshell
{
	char *cmd;
	char **arg;
	char *meta;
	struct microshell *next;
	
}				t_microshell;

t_microshell	init_str(void)
{
	t_microshell micro;

	micro.cmd = NULL;
	micro.arg = NULL;
	micro.meta = NULL;
	return micro;
}

t_microshell	*init_ptr(t_microshell *micro)
{

	micro->cmd = NULL;
	micro->arg = NULL;
	micro->meta = NULL;
	return micro;
}



int arg_count(char **av, int index)
{
	int count = 0;

	while (av[index] && strcmp(av[index],";") != 0 && strcmp(av[index], "|") != 0)
	{
		count += 1;
		index += 1;
	}
	return (count);
}

t_microshell	*filling_struct(char **av, t_microshell *micro)
{
	int i = 1 ;
	int check = 0;
	int count = 0;
	int j = 0;

	while (av[i])
	{
		while (av[i] && strcmp(av[i],";") != 0 && strcmp(av[i], "|") != 0)
		{
			if (check == 0)
			{
				micro->cmd = strdup(av[i]);
				check = 1;
				count = arg_count(av, i + 1);
				if (j == 0)
				{
					micro->arg = malloc(sizeof(char *) * count + 2);
					micro->arg[j] = strdup(micro->cmd); 
					j += 1;
				}
			}
			else
			{
				micro->arg[j] = strdup(av[i]);
				j += 1;
			} 
			micro->arg[j] = NULL;
			i += 1;


		}
		if (av[i] != NULL)
			micro->meta = strdup(av[i]);
		while (av[i] && strcmp(av[i], ";") == 0)
			i++;
		while (av[i] && strcmp(av[i], "|") == 0)
			i++;
		if (av[i])
		{
			
			micro->next = malloc(sizeof(t_microshell));
			micro = micro->next;
			micro = init_ptr(micro);
		}
		check = 0;
		j = 0;
	}
	micro->next = NULL;
	return (micro);	
}

void	execute(t_microshell *micro, char **env)
{
	pid_t pid;

	if (micro->cmd == NULL)
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (execve(micro->cmd, micro->arg, env) == -1)
			write(2, "error: cannot execute executable_that_failed\n", strlen("error: cannot execute executable_that_failed\n"));
	}
	waitpid(pid, NULL, WUNTRACED);
}

int count_arg(char **arg)
{
	int count = 0;
	if (arg == NULL)
		return 0;
	while (arg[count])
	{
		count += 1;
	}
	return (count);
}

t_microshell	*pipe_func(t_microshell *micro, char **env)
{
	int in = 0;
	int old_stdout = dup(STDIN_FILENO);
	pid_t pid;


	while (micro->meta && strcmp(micro->meta, "|") == 0)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			if (in != 0)
			{
				dup2(in, 0);
				close(in);
			}
			if (fd[1] != 1) 
			{
				dup2(fd[1], 1);
				close(fd[1]);
			}
			if (micro->cmd && strcmp(micro->cmd, "cd") == 0)
			{
				if (count_arg(micro->arg) > 2)
					write(2, "error: cd: bad arguments\n", strlen("error: cd: bad arguments\n"));
				else if (chdir(micro->arg[1]) == -1)
				{
					write(2, "error: cd: cannot change directory to path_to_change\n", strlen("error: cd: cannot change directory to path_to_change\n"));
				}
			}
			else	
			{
				execute(micro, env);
			}
			exit(EXIT_SUCCESS);
		}
		else
			waitpid(pid, NULL, WUNTRACED);
		if (in != 0)
			close(in);
		in = fd[0];
		close(fd[1]);
		micro = micro->next;
	}
	dup2(in, 0);
	close(in);
	if (micro->cmd && strcmp(micro->cmd, "cd") == 0)
	{
		if (count_arg(micro->arg) > 2)
			write(2, "error: cd: bad arguments\n", strlen("error: cd: bad arguments\n"));
		else if (chdir(micro->arg[1]) == -1)
		{
			write(2, "error: cd: cannot change directory to path_to_change\n", strlen("error: cd: cannot change directory to path_to_change\n"));
		}
	}
	else
	{
		execute(micro, env);
	}
	close(fd[1]);
	close(fd[0]);
	close(in);
	dup2(old_stdout, 0);
	return (micro);	
}

void	built_in(char **av, char **env, t_microshell *micro)
{
	filling_struct(av, micro);
	while (micro != NULL)
	{
		if (micro->cmd && micro->meta && strcmp(micro->meta, ";") == 0)
		{
			if (micro->cmd && strcmp(micro->cmd, "cd") == 0)
			{
				if (count_arg(micro->arg) > 2)
					write(2, "error: cd: bad arguments\n", strlen("error: cd: bad arguments\n"));
				else if (chdir(micro->arg[1]) == -1)
				{
					write(2, "error: cd: cannot change directory to path_to_change\n", strlen("error: cd: cannot change directory to path_to_change\n"));
				}
			}
			else
			{
				execute(micro, env);
			}
		}
		else if (micro->cmd && micro->meta && strcmp(micro->meta, "|") == 0)
		{
			micro = pipe_func(micro, env);
		}
		else 
		{
			if (micro->cmd && strcmp(micro->cmd, "cd") == 0)
			{
				if (count_arg(micro->arg) > 2)
					write(2, "error: cd: bad arguments\n", strlen("error: cd: bad arguments\n"));
				else if (chdir(micro->arg[1]) == -1)
				{
					write(2, "error: cd: cannot change directory to path_to_change\n", strlen("error: cd: cannot change directory to path_to_change\n"));
				}
			}
			else
				execute(micro, env);
		}
		micro = micro->next;
	}
}

int	main(int ac, char **av, char **env)
{
	t_microshell micro;

	if (ac < 2)
		return 0;
	micro = init_str();
	built_in(av, env, &micro);
	return (0);
}
