/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:17:29 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/17 17:26:57 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	parse(t_pex *pex, char **arg)
{
	init_pex(pex, arg);
	env_compare(pex);
	arg_struct(pex, arg);
}

void	arg_struct(t_pex *pex, char **arg)
{
	int i;

	i = 0;
	while (arg[++i])
		pex->arg[i - 1] = ft_strdup(ft_strjoin("/", arg[i]));
}
