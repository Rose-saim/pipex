/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:35:57 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:41:26 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_pipex
{
	pid_t	child_1;
	int		door[2];
	char	**paths_cmd;
	char	*cmd;
	char	**args_cmd;
}				t_pipex;

char	*ft_strjoin_connect(char *s1, char *s2, int c);
char	*get_next_line(int fd);
char	*get_path(char *cmd, char **env);
char	*get_cmd(char **paths, char *cmd);

int		argument_empty(char **av);
int		ft_strcmp(char *s1, char *s2);
int		manage_fd(char *file, int exit);
int		openfile(char *filename, int mode);

void	close_and_free(t_pipex *pipex);
void	exec(t_pipex *pipex, char *cmd, char **env);
void	free_dbl_pointer(char **pointer);
void	here_doc(char *limiter);
void	msg_error(char *str);
void	redir(t_pipex *pipex, char *cmd, char **env);
void	verif_dup2(int fd, int exit);
void	write_to_limiter(char *limiter, int door[]);

#endif