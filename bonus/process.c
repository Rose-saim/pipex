/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:13:59 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/27 10:19:52 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_pipex *pipex, char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = get_path(args[0], env);
	if (path == NULL)
	{
		free_dbl_pointer(args);
		free(path);
		msg_error("No find path command");
	}
	else
	{
		execve(path, args, env);
		waitpid(pipex->child_1, NULL, 0);
	}
}

void	redir(t_pipex *pipex, char *cmd, char **env)
{
	int	ret;

	ret = pipe(pipex->door);
	if (ret < 0)
		msg_error("Error pipe in redir");
	pipex->child_1 = fork();
	if (pipex->child_1 < 0)
		msg_error("Error fork in redir");
	if (pipex->child_1 != 0)
	{
		close(pipex->door[1]);
		verif_dup2(pipex->door[0], STDIN_FILENO);
		close(pipex->door[0]);
		waitpid(pipex->child_1, NULL, 0);
	}
	if (pipex->child_1 == 0)
	{
		close(pipex->door[0]);
		verif_dup2(pipex->door[1], STDOUT_FILENO);
		close(pipex->door[1]);
		exec(pipex, cmd, env);
	}
}

void	here_doc(char *limiter)
{
	pid_t	child;
	int		door[2];

	child = fork();
	if (child < 0)
		perror("Error fork in here_doc");
	if (child == 0)
		write_to_limiter(limiter, door);
	else
	{
		close(door[1]);
		verif_dup2(door[0], 0);
		close(door[0]);
		waitpid(child, NULL, 0);
	}
}
