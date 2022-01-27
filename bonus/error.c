/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:43:14 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:43:37 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *str)
{
	perror(str);
	exit (2);
}

void	verif_dup2(int fd, int exit)
{
	int	ret;

	ret = dup2(fd, exit);
	if (ret < 0)
		msg_error("Error dup2");
}

int	manage_fd(char *file, int exit)
{
	int	fd;

	fd = openfile(file, exit);
	verif_dup2(fd, exit);
	return (fd);
}

int	argument_empty(char **av)
{
	int	i;
	int	o;

	i = 0;
	while (av[i])
	{
		o = 0;
		while (av && av[i][o] && av[i][o] == ' ')
			++o;
		if (!(ft_strlen(*(av + i) + o) > 0))
			return (-1);
		++i;
	}
	return (1);
}
