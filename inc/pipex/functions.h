#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* parse.c */

void	parse(t_pex *pex, char **arg);
void	arg_struct(t_pex *pex, char **arg);

/* init_structs.c */

void	init_pex(t_pex *pex, char **arg);

/* env_compare.c */

void    env_compare(t_pex *pex);
void	search_command(t_pex *pex);

/* child_process.c */

int	create_child(t_pex *pex);
void	duplicate_fd(t_pex *pex);

/* error_msg.c */

int	error_msg(char *msg);

/* utils.c */

int	count_words(char **str);

#endif
