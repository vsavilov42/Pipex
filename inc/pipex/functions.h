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

/* error_msg.c */

int	no_args(void);
int	fnf(void);

/* utils.c */

int	count_words(char **str);

#endif
