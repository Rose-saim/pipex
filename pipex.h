/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:45:25 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 14:45:56 by myrmarti         ###   ########.fr       */
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
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	child_1;
	pid_t	child_2;
	int		door[2];
	int		fd_int;
	int		fd_out;
	char	**paths_cmd;
	char	*cmd;
	char	**args_cmd;
}				t_pipex;

char	*ft_strjoin_connect(char *s1, char *s2, int c);
char	**get_path(char **envp);

int		openfile(char *filename, int mode);
int		argument_empty(char **av);

void	verif_dup2(int fd, int exit);
void	close_and_free(t_pipex *pipex);
void	init_process(int ac, char **av, t_pipex *pipex);
void	first_child(t_pipex pipex, char **av, char **envp);
void	free_first_process(t_pipex *pipex);
void	free_second_process(t_pipex *pipex);
void	msg_error(char *str);
void	open_file(t_pipex *pipex, char **av);
void	second_child(t_pipex pipex, char **av, char **envp);

#endif