/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:34:07 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 13:34:08 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_after_nl(char *str)
{
	int		j;

	if (ft_strchr(str, '\n'))
	{
		j = (ft_strchr(str, '\n') + 1) - str;
		str = (ft_strchr(str, '\n') + 1);
		while (*str)
		{
			*(str - j) = *str;
			str++;
		}
		*(str - j) = 0;
		return ;
	}
	else
		str = ft_memset(str, 0, BUFFER_SIZE + 1);
	return ;
}

char	*ft_return(char *line, char *buff)
{
	if (ft_strlen(line) > 0 || ft_strlen(buff) > 0)
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			ret;
	char		*line;

	if (fd < 0 || read(fd, "", 0) < 0)
		return (NULL);
	line = NULL;
	ret = 1;
	if (buff[0] != 0)
		line = ft_realloc(line, buff);
	while (!ft_strchr(buff, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		line = ft_realloc(line, buff);
	}
	copy_after_nl(buff);
	return (ft_return(line, buff));
}
