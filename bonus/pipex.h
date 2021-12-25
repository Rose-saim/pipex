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
char	*get_path(char *cmd, char **env);
char	**ft_split(char *s, char c);
char	*get_cmd(char **paths, char *cmd);

int argument_empty(char **av);
int	get_next_line(int fd, char **line);
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_strlen(char *str);

void	close_and_free(t_pipex *pipex);
void	exec(char *cmd, char **env);
void	here_doc(char *limiter);
void	msg_error(char *str);
void	redir(char *cmd, char **env);
void	open_file(t_pipex *pipex, char **av);
void	verif_dup2(int fd, int exit);
void	write_to_limiter(char *limiter, int door[]);

#endif