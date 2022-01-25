/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:46:10 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 13:45:18 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_first_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->args_cmd[i])
	{
		free((pipex->args_cmd[i]));
		++i;
	}
	free(pipex->args_cmd);
}

void	free_second_process(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->paths_cmd[i])
	{
		free(pipex->paths_cmd[i]);
		++i;
	}
	free(pipex->paths_cmd);
	close_and_free(pipex);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*command;

	while (*paths)
	{
		command = ft_strjoin_connect(*paths, cmd, '/');
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char	**av, char	**envp)
{
	close(pipex.door[0]);
	verif_dup2(pipex.fd_int, 0);
	verif_dup2(pipex.door[1], 1);
	pipex.args_cmd = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.paths_cmd, pipex.args_cmd[0]);
	if (pipex.cmd == NULL)
	{
		free_first_process(&pipex);
		free_second_process(&pipex);
		msg_error("Command doesn't exists");
	}
	execve(pipex.cmd, pipex.args_cmd, envp);
}

void	second_child(t_pipex pipex, char **av, char **envp)
{
	close(pipex.door[1]);
	verif_dup2(pipex.fd_out, 1);
	verif_dup2(pipex.door[0], 0);
	pipex.args_cmd = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.paths_cmd, pipex.args_cmd[0]);
	if (pipex.cmd == NULL)
	{
		free_first_process(&pipex);
		free_second_process(&pipex);
		msg_error("Command doesn't exists");
		exit (2);
	}
	execve(pipex.cmd, pipex.args_cmd, envp);
}
