#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_pipe
{
    pid_t   proc1;
    pid_t   proc2;
    int std[2];
    int int_fd;
    int out_fd;
    char    *paths;
    char    *command;
    char    **paths_command;
    char    **paths_argument;
}               t_pipe;

void    ft_pipex(t_pipe pipex, char **av, char **envp);
void	first_process(t_pipe pipex, char **av, char **envp);
void	second_process(t_pipe pipex, char **av, char **envp);


#endif