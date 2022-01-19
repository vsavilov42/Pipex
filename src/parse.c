/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:17:29 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/18 20:15:57 by Vsavilov         ###   ########.fr       */
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

	i = -1;
	while (arg[++i])
	{
		if (i % 2 != 0)
			pex->arg[i] = ft_strdup(ft_strjoin("/", arg[i]));
		else
			pex->arg[i] = arg[i];
	}
	pex->arg[i] = NULL;
}
