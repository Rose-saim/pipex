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

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		++i;
	return (i);
}


int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				r;

	r = 0;
	i = 0;
	while ((s1[i] || s2[i]) && r == 0 && i < n)
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
		}
		i++;
	}
	return (r);
}
