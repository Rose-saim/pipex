/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:39:15 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:34:27 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == 0)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, "pipex: ", 7);
			write(STDERR_FILENO, filename, ft_strlen(filename));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (STDIN_FILENO);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

void	write_to_limiter(char *limiter, int door[])
{
	char	*line;
	int		i;

	close(door[0]);
	i = 0;
	while (i == 0 || !line)
	{
		line = get_next_line(0);
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			close(door[1]);
			exit (1);
		}
		i = 1;
		write(1, "heredoc>", 8);
		write(door[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(door[1]);
	perror("ERROR");
}

int	main(int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;
	int	i;

	if (ac < 5)
		msg_error("Invalid number of arguments\n");
	if (argument_empty(av) == -1)
		msg_error("Argument empty");
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		here_doc(av[2]);
	}
	else
	{
		i = 2;
		fdin = manage_fd(av[1], 0);
		close(fdin);
	}
	while (i < ac - 2)
		redir(av[i++], env);
	fdout = manage_fd(av[ac - 1], 1);
	close (fdout);
	exec(av[ac - 2], env);
	return (1);
}
