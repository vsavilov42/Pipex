#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* utils.c */

int	errormsg(char *str);
void	heredoc_child(t_pex *pex, char *argv);

/* main.c */

void	pipe_red(t_pex *pex, char *command);
void	child_process(t_pex *pex, char *command);
void	command_path(t_pex *pex);
void	heredoc_handler(t_pex *pex, int argc, char **argv);

#endif
