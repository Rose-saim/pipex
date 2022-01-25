/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:13:59 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:15:04 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;
	int		ret;

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
		ret = execve(path, args, env);
		if (ret < 0)
			msg_error("Error about execve");
		else
			msg_error("Error about execve");
		exit(1);
	}
}

void	redir(char *cmd, char **env)
{
	pid_t	child;
	int		ret;
	int		door[2];

	ret = pipe(door);
	if (ret < 0)
		msg_error("Error pipe in redir");
	child = fork();
	if (child < 0)
		msg_error("Error fork in redir");
	if (child)
	{
		close(door[1]);
		verif_dup2(door[0], STDIN_FILENO);
		close(door[0]);
		waitpid(child, NULL, 0);
	}
	else
	{
		close(door[0]);
		verif_dup2(door[1], STDOUT_FILENO);
		close(door[1]);
		exec(cmd, env);
	}
}

void	here_doc(char *limiter)
{
	pid_t	child;
	int		door[2];
	int		ret;

	write(1, "heredoc>", 8);
	ret = pipe(door);
	if (ret < 0)
		msg_error("Error pipe in here_doc");
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
