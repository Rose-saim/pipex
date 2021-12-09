#include "pipex.h"

void    ft_pipex(t_pipe pipex, char **av, char **envp)
{
    int status;

    pipe(pipex.std);
    pipex.proc1 = fork();
    if (pipex.proc1 < 0)
        ft_error (infile);
    if (pipex.proc1 == 0)
        first_process(pipex, av, envp);
    pipex.proc2 = fork();
    if (pipex.proc2 < 0)
        ft_error (outfile);
    if (pipex.proc2 == 0)
        second_process(pipex, av, envp);
    close(pipex.std[0]);
    close(pipex.std[1]);
    waitpid(pipex.proc1, &status, 0);
    waitpid(pipex.proc2, &status, 0);
}

int main(int ac, char **av, char **envp)
{
    t_pipe  pipex;

    if (ac == 5)
    {
        pipex.int_fd = open(av[1], O_RDONLY);
        if (pipex.int_fd < 0)
            ft_error (ERROR);
        pipex.out_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
        if (pipex.out_fd < 0)
            ft_error (ERROR);
        ft_pipex(pipex, av, envp);
    }
    else
        return (EXIT);
    return (0);
}