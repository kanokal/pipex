/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/12 22:11:06 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_struct_set(t_pipex *var, int argc, char **argv, char **envp)
{
	var->last = argc;
	var->argv = argv;
	var->envp = envp;
}

static void	pipex_fork(t_pipex var)
{
	int	err;
	int	pid;

	pid = fork();
	if (pid == 0)
		pipex_child(var);
	else if (pid > 0)
	{
		wait(&err);
		if (err != 0)
		{
			close(var.fd[0]);
			close(var.fd[1]);
			exit(err);
		}
		var.cur++;
		if (var.cur == 2)
			var.cur++;
		if (var.cur == var.last - 1)
			pipex_parent(var);
		else if (var.cur < var.last - 1)
			return (pipex_fork(var));
		else
		{
			write(2, "error\n", 6);
			exit(-1);
		}
	}
	else
	{
		perror("fork");
		exit(-2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	pipex_struct_set(&var, argc - 1, argv, envp);
	var.cur = 1;
	if (argc > 4)
	{
		if (pipe(var.fd) < 0)
		{
			perror("pipe");
			exit(errno);
		}
		pipex_fork(var);
	}
	else if (argc == 4)
		pipex_one(var);
	return (0);
}
