/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 17:04:00 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_fork_do(t_pipex *var, int *idx)
{
	int		wstatus;
	pid_t	pipex_pid;

	pipex_pid = fork();
	if (pipex_pid == 0)
		return (pipex_child(*var));
	else if (pipex_pid > 0)
	{
		close(var->fd[1]);
		while ((wait(&wstatus)) > 0)
			;
		close(var->fd[0]);
		if (WEXITSTATUS(wstatus) == 0)
		{
			var->cur++;
			(*idx)++;
		}
		else
			exit(1);
	}
	else
		pipex_fork_error();
}

static void	pipex_pipe_set(t_pipex *var, int fd[][2], int idx)
{
	if (idx == 0)
	{
		var->fd[0] = open(var->infile, O_RDONLY);
		if (var->fd[0] < 0)
			pipex_open_error();
		var->fd[1] = fd[idx][1];
	}
	else if (idx == var->cmd_count - 1)
	{
		var->fd[1] = open(var->outfile, O_WRONLY | O_CREAT | O_TRUNC,
							S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (var->fd[1] < 0)
			pipex_open_error();
		var->fd[0] = fd[idx - 1][0];
	}
	else
	{
		var->fd[0] = fd[idx - 1][0];
		var->fd[1] = fd[idx][1];
	}
}

void		pipex_fork(t_pipex var)
{
	int		idx;
	int		fd[var.cmd_count - 1][2];

	idx = 0;
	while (idx < var.cmd_count - 1)
	{
		if (pipe(fd[idx]) < 0)
			pipex_pipe_error();
		idx++;
	}
	idx = 0;
	while (idx < var.cmd_count)
	{
		pipex_pipe_set(&var, fd, idx);
		pipex_fork_do(&var, &idx);
	}
}
