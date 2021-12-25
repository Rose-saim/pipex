#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <ctype.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		error(int fd, char *buff);
int		copy_after_nl(char *str);

char	*ft_realloc(char *line, char *buff);
char	*ft_strchr(const char *s, int c);

void	*ft_memset( void *pointer, int value, size_t count);
void	*ft_memcpy(void *dest, void *src, size_t n);
int	ft_strlen(char *s);

#endif