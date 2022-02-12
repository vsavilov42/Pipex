/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:09:27 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/12 23:09:29 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	errormsg(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}
