#include <pipex.h>

void    env_compare(t_pex *pex)
{
    extern char **environ;
    char *rut;
    int i;

    i = -1;
    while (environ[++i])
    {
        if (ft_strncmp(environ[i], "PATH=", 5) == 0)
        {
            rut = ft_substr(environ[i], 5, ft_strlen(environ[i]));
            pex->path = ft_split(rut, ':');
            break ; 
        }
    }
}

void	search_command(t_pex *pex)
{
	int	i;
	int	j;

	i = -1;
	while (pex->arg[++i])
	{
		j = -1;
		while (pex->path[++j])
			if (!access(ft_strjoin(pex->path[j], pex->arg[i]), X_OK))
			{
				printf("command valid");
			}
	}
	//command not found
}
