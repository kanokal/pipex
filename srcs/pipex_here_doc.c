/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:40:16 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 20:21:08 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_here_doc_do(t_pipex *var, int *idx)
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
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
		pipex_fork_error();
}

static void	pipex_here_doc_pipe_set(t_pipex *var, int *in, int **fd, int idx)
{
	if (idx == 0)
	{
		var->fd[0] = in[0];
		var->fd[1] = fd[idx][1];
	}
	else if (idx == var->cmd_count - 1)
	{
		var->fd[1] = open("outfile", O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (var->fd[1] < 0)
			pipex_open_error();
		var->fd[0] = fd[idx - 1][0];
	}
	else
	{
		var->fd[0] = fd[idx - 1][1];
		var->fd[1] = fd[idx][0];
	}
}

static void	pipex_fork_here_doc(t_pipex var, int infile[2])
{
	int		idx;
	int		**fd;

	fd = pipex_create_pipe(var.cmd_count - 1);
	idx = 0;
	while (idx < var.cmd_count)
	{
		pipex_here_doc_pipe_set(&var, infile, fd, idx);
		pipex_here_doc_do(&var, &idx);
	}
	fd = ft_free_2d_i(fd);
}

void	pipex_here_doc(t_pipex var)
{
	int		gnl_ret;
	int		infile[2];
	char	*line;

	if (pipe(infile) < 0)
		pipex_pipe_error();
	while (1)
	{
		gnl_ret = get_next_line(0, &line);
		if (gnl_ret < 0)
			break ;
		if (ft_strncmp(line, var.argv[2], ft_strlen(var.argv[2]) + 1) == 0)
		{
			ft_free_ptr(&line);
			break ;
		}
		write(infile[1], line, ft_strlen(line));
		write(infile[1], "\n", 1);
		free(line);
	}
	close(infile[1]);
	if (gnl_ret < 0)
		ft_error_handling("error: gnl failed\n");
	return (pipex_fork_here_doc(var, infile));
}
