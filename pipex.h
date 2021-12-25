#ifndef PIPEX_H
#define PIPEX_H

# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_pipex
{
	pid_t	child_1;
	pid_t	child_2;
	int door[2];
	int fd_int;
	int fd_out;
	char    **paths_cmd;
	char    *cmd;
	char	**args_cmd;
}               t_pipex;

char	*ft_strjoin_connect(char *s1, char *s2, int c);
char	**get_path(char **envp);
char	**ft_split(char *s, char c);

int argument_empty(char **av);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_strlen(char *str);

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