/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:10:51 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_fork_do(t_pipex *var, int *idx, int **fd)
{
	int		wstatus;
	pid_t	pipex_pid;

	pipex_pid = fork();
	if (pipex_pid == 0)
		return (pipex_child(*var, fd));
	else if (pipex_pid > 0)
	{
		close(var->fd[1]);
		while ((wait(&wstatus)) > 0)
			;
		close(var->fd[0]);
		if (WEXITSTATUS(wstatus) != 0)
			pipex_error_handling(NULL, "error: error in child process\n", fd);
		var->cur++;
		(*idx)++;
	}
	else
		pipex_error_handling("fork", NULL, fd);
}

static void	pipex_pipe_set(t_pipex *var, int **fd, int idx)
{
	if (idx == 0)
	{
		var->fd[0] = open(var->infile, O_RDONLY);
		if (var->fd[0] < 0)
			pipex_error_handling("open", NULL, fd);
		var->fd[1] = fd[idx][1];
	}
	else if (idx == var->cmd_count - 1)
	{
		var->fd[1] = open(var->outfile, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (var->fd[1] < 0)
			pipex_error_handling("open", NULL, fd);
		var->fd[0] = fd[idx - 1][0];
	}
	else
	{
		var->fd[0] = fd[idx - 1][0];
		var->fd[1] = fd[idx][1];
	}
}

void	pipex_fork(t_pipex var)
{
	int		idx;
	int		**fd;

	fd = pipex_create_pipe(var.cmd_count - 1);
	idx = 0;
	while (idx < var.cmd_count)
	{
		pipex_pipe_set(&var, fd, idx);
		pipex_fork_do(&var, &idx, fd);
	}
	fd = ft_free_2d_i(fd);
}
