/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:13:51 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/19 14:22:16 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

//Check path
//verify perm (access)
//Strjoin path + command (parse)
//create child

void	leaks(void)
{
	system("leaks Pipex");
}

int	main(int argc, char **argv)
{
	t_pex	pex;

	if (argc < 2)
		return (error_msg("Usage: Command1 + arg1 | Command2 + arg2...\n"));
	//leaks();
	parse(&pex, argv);
	create_child(&pex);
	//search_command(&pex);
	return (0);
}
