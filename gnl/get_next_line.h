/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:43 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 13:33:53 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# if (BUFFER_SIZE < 0)
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_realloc(char *line, char *buff);
char	*ft_return(char *line, char *buff);
char	*ft_strchr(const char *s, int c);

void	copy_after_nl(char *str);
void	*ft_memset( void *pointer, int value, size_t count);

#endif