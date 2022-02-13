/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:53:34 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/13 18:16:09 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pex
{
	char	**cmmd;
	char	*cmmd_path;
	char	*env;
	int		index;
	int		fd_io[2];
	int		pipe_fd[2];
	pid_t	pid;
}	t_pex;

#endif
