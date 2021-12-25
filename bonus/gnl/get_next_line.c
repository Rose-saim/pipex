#include "../pipex.h"
#include "get_next_line.h"

int	copy_after_nl(char *str)
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
		return (1);
	}
	else
		str = ft_memset(str, 0, BUFFER_SIZE + 1);
	return (0);
}

int	error(int fd, char *buff)
{
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, "", 0) < 0 || read(fd, buff, 0) < 0)
		return (-1);
	return (1);
}

int	ft_return(int ret, char *buff, int j)
{
	if (ret < 0)
		return (-1);
	if (ft_strlen(buff) == 0 && ret < BUFFER_SIZE && j == 0)
		return (0);
	if (ret > 0 || j > 0)
		return (1);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char static	buff[BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	ret = error(fd, buff);
	if (*buff != 0)
		*line = ft_realloc(*line, buff);
	while (!ft_strchr(buff, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		*line = ft_realloc(*line, buff);
		if (ret < 1 || buff[0] == '\0')
			break ;
	}
	ret = ft_return(ret, buff, copy_after_nl(buff));
	return (ret);
}
