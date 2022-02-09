#include <pipex.h>

int	main(int argc, char **argv)
{
	t_pex	*pex;
	int	i;

	i = -1;
	pex = (t_pex *)ft_calloc(1, sizeof(t_pex));
	if ((argc >= 5 && ft_strncmp("here_doc", argv[1], 9)) || argc >= 6)
	{
		if (!ft_strncmp("here_doc", argv[1], 9))
		{
			//TODO: heredoc
		}
		else
		{
			pex->fd_io[0] = open(argv[1], O_RDONLY);
			pex->fd_io[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(pex->fd_io[0], STDIN_FILENO);
		}
		while (++i < argc - 2)
			pipe_red(pex, argv[i]);
	}
	return (0);
}

void	child_process(t_pex *pex, char *command)
{
	int	i;
	extern char **environ;

	i = 0;
	pex->cmmd = ft_split(command, ' ');
	if (**pex->cmmd == '/' || **pex->cmmd == '.' || access(*pex->cmmd, X_OK) == 0)
		pex->cmmd_path = *pex->cmmd;
	else
	{
		while (environ[i] && ft_strncmp("PATH=", environ[i], 5))
			i++;
	}

}

void	pipe_red(t_pex *pex, char *command)
{
	int	stat_loc;

	if (pipe(pex->pipe_fd) == -1)
		exit(errormsg("Error: pipe failure.\n"));
	pex->pid = fork();
	if (pex->pid == -1)
		exit(errormsg("Error: pid failure.\n"));
	if (pex->pid > 0)
	{
		close(pex->pipe_fd[1]);
		dup2(pex->pipe_fd[0], STDIN_FILENO);
		close(pex->pipe_fd[0]);
		waitpid(pex->pid, &stat_loc, 0);
		if (WEXITSTATUS(stat_loc) == 1)
			exit(errormsg("Error: waitpid failure.\n"));
	}
	else
	{
		close(pex->pipe_fd[0]);
		dup2(pex->pipe_fd[1], STDIN_FILENO);
		close(pex->pipe_fd[1]);
		child_process(pex, command);
		printf("%s\n", command);
	}
}
