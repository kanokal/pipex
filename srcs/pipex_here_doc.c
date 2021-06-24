/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:40:16 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 16:20:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_fork_here_doc(t_pipex var, int cmd_count, int infile[2])
{
	int		idx;
	int		outfile;
	int		wstatus;
	int		pipe_fd[cmd_count - 1][2];
	pid_t	pipex_pid;

	idx = 0;
	while (idx < cmd_count - 1)
	{
		if (pipe(pipe_fd[idx]) < 0)
			pipex_pipe_error();
		idx++;
	}
	idx = 0;
	while (idx < cmd_count)
	{
		if (idx == 0)
		{
			var.fd[0] = infile[0];
			var.fd[1] = pipe_fd[idx][1];
		}
		else if (idx == cmd_count - 1)
		{
			outfile = open("outfile", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (outfile < 0)
				pipex_open_error();
			var.fd[0] = pipe_fd[idx - 1][0];
			var.fd[1] = outfile;
		}
		else
		{
			var.fd[0] = pipe_fd[idx - 1][1];
			var.fd[1] = pipe_fd[idx][0];
		}
		pipex_pid = fork();
		if (pipex_pid == 0)
			return (pipex_child(var));
		else if (pipex_pid > 0)
		{
			close(var.fd[1]);
			wait(&wstatus);
			close(var.fd[0]);
			if (WIFEXITED(wstatus))
			{
				var.cur++;
				idx++;
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
}

void	pipex_here_doc(t_pipex var, int cmd_count)
{
	int		gnl_ret;
	int		infile[2];
	char	*line;

	if (pipe(infile) < 0)
		pipex_pipe_error();
	while ((gnl_ret = get_next_line(0, &line)) >= 0)
	{
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
	var.cur = 3;
	return (pipex_fork_here_doc(var, cmd_count, infile));
}
