/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:34:21 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 13:34:22 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char )*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_realloc(char *s1, char *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	if (ft_strchr(s2, '\n'))
		len_s2 = (ft_strchr(s2, '\n') + 1) - s2;
	else
		len_s2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len_s2 + len_s1 + 1));
	if (!newstr)
		return (0);
	ft_memcpy(newstr, s1, len_s1);
	ft_memcpy(newstr + len_s1, s2, len_s2);
	newstr[len_s1 + len_s2] = 0;
	free(s1);
	return (newstr);
}
