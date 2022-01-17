#include <pipex.h>

int	no_args(void)
{
	write(2, "Usage: Command1 [command args], Command2 [command args]\n", 56);
	return (1);
}

int	fnf(void)
{
	write(2, "File not found\n", 16);
	return (1);
}
