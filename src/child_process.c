#include <pipex.h>

int	create_child(t_pex *pex)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		exit(error_msg("Fork error\n"));
	else if (pid == 0)
	{
		duplicate_fd(pex);
		exit(1);
	}
	else
		return (0);
}

void	duplicate_fd(t_pex *pex)
{
	//dup2 usage
}
