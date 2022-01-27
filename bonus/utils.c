/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:18:19 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:18:33 by myrmarti         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*command;

	while (*paths)
	{
		command = ft_strjoin_connect(*paths, cmd, '/');
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	free_dbl_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		++i;
	}
	free(pointer[i]);
	free(pointer);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*bin;

	while (ft_strncmp(*envp, "PATH", 4))
		++envp;
	paths = ft_split(*envp + 5, ':');
	bin = get_cmd(paths, cmd);
	free_dbl_pointer(paths);
	return (bin);
}
