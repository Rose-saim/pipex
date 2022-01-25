/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:49:53 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 11:50:31 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	**paths;

	paths = NULL;
	while (*envp && ft_strncmp("PATHS", *envp, 4) != 0)
		++envp;
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

void	msg_error(char *str)
{
	perror(str);
	exit (2);
}

void	close_and_free(t_pipex *pipex)
{
	close(pipex->door[0]);
	close(pipex->door[1]);
	close(pipex->fd_out);
	close(pipex->fd_int);
}

void	init_process(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
		msg_error("Numbers of arguments is wrong");
	if (argument_empty(av) == -1)
		msg_error("Argument empty");
	pipex->fd_int = open(av[1], O_RDONLY);
	if (pipex->fd_int < 0)
		msg_error("Intfile no exist");
	pipex->fd_out = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->fd_out < 0)
		msg_error("file no exist");
	if (pipe(pipex->door) < 0)
		msg_error("pipe error");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_process(ac, av, &pipex);
	pipex.paths_cmd = get_path(envp);
	pipex.child_1 = fork();
	if (pipex.child_1 == 0)
		first_child(pipex, av, envp);
	waitpid(pipex.child_1, NULL, 0);
	pipex.child_2 = fork();
	if (pipex.child_2 == 0)
		second_child(pipex, av, envp);
	free_second_process(&pipex);
	waitpid(pipex.child_2, NULL, 0);
	return (0);
}
