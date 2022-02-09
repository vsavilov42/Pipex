/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:53:34 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/09 17:51:56 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pex
{
	char	**cmmd;
	char	*cmmd_path;
	char	*env;
	int	fd_io[2];
	int	pipe_fd[2];
	pid_t	pid;
}	t_pex;

#endif
