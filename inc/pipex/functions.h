#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* utils.c */

int	errormsg(char *str);

/* main.c */

void	pipe_red(t_pex *pex, char *command);
void	child_process(t_pex *pex, char *command);
char	*command_path(t_pex *pex);

#endif
