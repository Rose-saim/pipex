#include "pipex.h"

char	*path_command(char **paths, char *cmd)
{
	char	*command;

	command = ft_strjoin(*paths, "/");
	command = ft_strjoin(command, cmd);
}

char	pars_cmd(char **paths, char *cmd)
{
	char	*command;

	while (*paths)
	{
		command = path_command(*paths, cmd);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		++paths;
	}
	return (NULL);
}

void	first_process(t_pipe pipex, char **av, char **envp)
{

	dup2(pipex.std[1], STDOUT_FILENO);
	dup2(pipex.int_fd, STDIN_FILENO);
	close (pipex.std[0]);
	pipex.paths = substr(envp);
	pipex.paths_command = ft_split(pipex.paths, ':');
	pipex.paths_argument = ft_split(av[2], ' ');
	pipex.command = pars_cmd(pipex.paths_command, pipex.paths_argument[0]);
	if (!pipex.command)
	{
		free(pipex.command);
		ft_error();
		exit (1);
	}
	execve(pipex.command, pipex.paths_argument, envp);
}

void	second_process(t_pipe pipex, char **av, char **envp)
{
	dup2(pipex.out_fd, STDOUT_FILENO);
	dup2(pipex.std[0], STDIN_FILENO);
	close (pipex.std[1]);
	pipex.paths_argument = ft_split(av[3], ' ');
	pipex.command = pars_cmd(pipex.paths_command, pipex.paths_argument[0]);
	if (!pipex.command)
	{
		free(pipex.command);
		ft_error();
		exit(1);
	}
	execve(pipex.command, pipex.paths_argument, envp);
}