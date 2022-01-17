#include <pipex.h>

int	count_words(char **str)
{
	int	words;

	words = 0;
	if (!str)
		return (0);
	while (str[words])
		words++;
	return (words);
}
