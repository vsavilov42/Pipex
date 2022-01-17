/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:13:51 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/17 17:21:13 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

//Check path
//verify perm (access)
//Strjoin path + command (parse)

void	leaks(void)
{
	system("leaks Pipex");
}

int	main(int argc, char **argv)
{
	t_pex	pex;

	if (argc < 2)
		return (no_args());
	//leaks();
	parse(&pex, argv);
	search_command(&pex);
	return (0);
}
