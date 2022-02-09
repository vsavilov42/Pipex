#include <pipex.h>

int	errormsg(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}
