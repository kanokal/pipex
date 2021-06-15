/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/15 21:57:11 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_struct_set(t_pipex *var, int last, char **argv, char **envp)
{
	var->last = last;
	var->argv = argv;
	var->envp = envp;
}

static void	pipex_fork(t_pipex var)
{
	int	err;
	int	pid;

	pid = fork();
	if (pid == 0)
		return (pipex_child(var));
	else if (pid > 0)
	{
		wait(&err);
		if (err < 0 || err == 65280)
		{
			close(var.fd[0]);
			close(var.fd[1]);
			write(2, "error: child process stopped\n", 29);
			exit(err);
		}
		var.cur += 2;
		return (pipex_parent(var));
	}
	else
	{
		close(var.fd[0]);
		close(var.fd[1]);
		perror("fork");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	var.cur = 1;
	pipex_struct_set(&var, argc - 1, argv, envp);
	if (argc > 4)
	{
		if (pipe(var.fd) < 0)
		{
			perror("pipe");
			exit(errno);
		}
		pipex_fork(var);
	}
	return (0);
}
