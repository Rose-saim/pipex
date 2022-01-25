/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:48:31 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 13:45:13 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_connect(char *s1, char *s2, int c)
{
	char	*to_return;
	int		i;
	int		o;

	i = ft_strlen(s1) + ft_strlen(s2);
	to_return = malloc(sizeof(char) * (i + c + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		to_return[i] = s1[i];
		++i;
	}
	to_return[i++] = c;
	o = 0;
	while (s2[o])
		to_return[i++] = s2[o++];
	to_return[i] = 0;
	return (to_return);
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

void	verif_dup2(int fd, int exit)
{
	int	ret;

	ret = dup2(fd, exit);
	if (ret < 0)
		msg_error("Error dup2");
}
