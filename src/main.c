/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:09:22 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/02/13 18:09:43 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv)
{
	t_pex	*pex;

	pex = (t_pex *)ft_calloc(1, sizeof(t_pex));
	pex->index = 1;
	if (argc >= 5)
	{
		if (!ft_strncmp("here_doc", argv[1], 9))
			heredoc_handler(pex, argc, argv);
		else
		{
			pex->fd_io[0] = open(argv[1], O_RDONLY);
			if (pex->fd_io[0] == -1)
				exit(errormsg("Error: Permissions denied.\n"));
			pex->fd_io[1] = open(argv[argc - 1],
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(pex->fd_io[0], STDIN_FILENO);
		}
		while (++pex->index < argc - 2)
			pipe_red(pex, argv[pex->index]);
		dup2(pex->fd_io[1], STDOUT_FILENO);
		child_process(pex, argv[argc - 2]);
	}
	errormsg("Usage: ./pipex infile command1 command2... outfile.\n");
	free(pex);
	return (0);
}

void	heredoc_handler(t_pex *pex, int argc, char **argv)
{
	if (pipe(pex->pipe_fd) == -1)
		exit(errormsg("Error: pipe failure.\n"));
	pex->pid = fork();
	if (pex->pid == -1)
		exit(errormsg("Error: pid failure.\n"));
	if (pex->pid > 0)
	{
		close(pex->pipe_fd[1]);
		dup2(pex->pipe_fd[0], STDIN_FILENO);
		close(pex->pipe_fd[0]);
		waitpid(pex->pid, NULL, 0);
	}
	else
		heredoc_child(pex, argv[2]);
	pex->fd_io[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pex->index = 2;
}

void	command_path(t_pex *pex)
{
	char	**env;
	char	*tmp;
	int		i;

	env = ft_split(pex->env, ':');
	i = -1;
	tmp = ft_strjoin("/", *pex->cmmd);
	while (env[++i])
	{
		if (access(ft_strjoin(env[i], tmp), X_OK) == 0)
			pex->cmmd_path = ft_strjoin(env[i], tmp);
	}
	if (!pex->cmmd_path)
		exit(errormsg("Error: Command not found.\n"));
}

void	child_process(t_pex *pex, char *command)
{
	int			i;
	extern char	**environ;

	i = -1;
	pex->cmmd = ft_split(command, ' ');
	if (**pex->cmmd == '/' || **pex->cmmd == '.'
		|| access(*pex->cmmd, X_OK) == 0)
		pex->cmmd_path = *pex->cmmd;
	else
	{
		while (environ[++i])
			if (ft_strncmp("PATH=", environ[i], 5) == 0)
				pex->env = ft_substr(environ[i], 5, ft_strlen(environ[i]));
		if (!pex->env)
			exit(errormsg("Error: path not found.\n"));
		command_path(pex);
	}
	execve(pex->cmmd_path, pex->cmmd, environ);
}

void	pipe_red(t_pex *pex, char *command)
{
	if (pipe(pex->pipe_fd) == -1)
		exit(errormsg("Error: pipe failure.\n"));
	pex->pid = fork();
	if (pex->pid == -1)
		exit(errormsg("Error: pid failure.\n"));
	if (pex->pid > 0)
	{
		close(pex->pipe_fd[1]);
		dup2(pex->pipe_fd[0], STDIN_FILENO);
		close(pex->pipe_fd[0]);
		dup2(pex->fd_io[1], STDOUT_FILENO);
		waitpid(pex->pid, NULL, 0);
	}
	else
	{
		close(pex->pipe_fd[0]);
		dup2(pex->pipe_fd[1], STDOUT_FILENO);
		close(pex->pipe_fd[1]);
		child_process(pex, command);
	}
}
