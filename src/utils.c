/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:09:27 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/13 18:01:40 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	errormsg(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

void	heredoc_child(t_pex *pex, char *argv)
{
	char	*line;
	char	*del;

	del = ft_strjoin(argv, "\n");
	close(pex->pipe_fd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, del, ft_strlen(del) + 1))
			exit(1);
		ft_putstr_fd(line, pex->pipe_fd[1]);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(pex->pipe_fd[1]);
	free(line);
	free(del);
}
