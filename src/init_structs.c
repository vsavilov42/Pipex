#include <pipex.h>

void	init_pex(t_pex *pex, char **arg)
{
	pex->arg = (char **)malloc(sizeof(char *) * count_words(arg) + 1);
	if (!pex->arg)
		exit(1);
}
