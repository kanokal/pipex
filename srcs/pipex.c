/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 16:44:00 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_struct_set(t_pipex *var, int last, char **argv, char **envp)
{
	var->last = last;
	var->argv = argv;
	var->envp = envp;
}

static void	pipex_fork(t_pipex var, int cmd_count)
{
	int		idx;
	int		infile;
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
			infile = open("infile", O_RDONLY);
			if (infile < 0)
				pipex_open_error();
			var.fd[0] = infile;
			var.fd[1] = pipe_fd[idx][1];
		}
		else if (idx == cmd_count - 1)
		{
			outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (outfile < 0)
				pipex_open_error();
			var.fd[0] = pipe_fd[idx - 1][0];
			var.fd[1] = outfile;
		}
		else
		{
			var.fd[0] = pipe_fd[idx - 1][0];
			var.fd[1] = pipe_fd[idx][1];
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	pipex_struct_set(&var, argc - 1, argv, envp);
	if (argc > 4)
	{
		if (argc > 5 && ft_strncmp(argv[1], "here_doc", 9) == 0)
			pipex_here_doc(var, argc - 4);
		else
		{
			var.cur = 2;
			pipex_fork(var, argc - 3);
		}
	}
	return (0);
}
