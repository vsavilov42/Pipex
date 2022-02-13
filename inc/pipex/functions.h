/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:15:29 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/13 18:15:50 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* utils.c */

int		errormsg(char *str);
void	heredoc_child(t_pex *pex, char *argv);

/* main.c */

void	pipe_red(t_pex *pex, char *command);
void	child_process(t_pex *pex, char *command);
void	command_path(t_pex *pex);
void	heredoc_handler(t_pex *pex, int argc, char **argv);

#endif
