#include "get_next_line.h"

void	*ft_memset( void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*num;

	i = 0;
	num = (unsigned char *)pointer;
	while (i < count)
	{
		num[i++] = (unsigned char)value;
	}
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
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

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	i = 0;
	str_1 = (unsigned char *)dest;
	str_2 = (unsigned char *)src;
	if (!str_1 && !str_2)
		return (NULL);
	while (i < n)
	{
		str_1[i] = (unsigned char)str_2[i];
		i++;
	}
	return (dest);
}

char	*ft_realloc(char *s1, char *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	if (ft_strchr(s2, '\n'))
		len_s2 = ft_strchr(s2, '\n') - s2;
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
