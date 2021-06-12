/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/12 22:12:06 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_child_err(char **path, char**cmd)
{
	ft_free_split(path);
	ft_free_split(cmd);
	write(2, "execve: invalid command\n", 24);
	exit(errno);
}

static void	pipex_child_do(t_pipex var)
{
	int		idx;
	char	**path;
	char	**cmd;
	char	*execve_path;

	pipex_get_path_n_cmd(&path, &cmd, var);
	idx = 0;
	while (path[idx] != 0)
	{
		execve_path = pipex_set_path(idx++, path, cmd);
		execve(execve_path, cmd, var.envp);
		ft_free_ptr(&execve_path);
	}
	return (pipex_child_err(path, cmd));
}

void		pipex_child(t_pipex var)
{
	int		infile;

	if (dup2(var.fd[1], 1) < 0)
		pipex_dup2_error(var, 1);
	infile = -1;
	if (var.cur == 1)
	{
		infile = open(var.argv[var.cur++], O_RDONLY);
		if (infile < 0)
			pipex_open_error();
		if (dup2(infile, 0) < 0)
		{
			close(infile);
			pipex_dup2_error(var, 1);
		}
		close(infile);
	}
	else if (dup2(var.fd[0], 0) < 0)
		pipex_dup2_error(var, 1);
	close(var.fd[0]);
	close(var.fd[1]);
	return (pipex_child_do(var));
}

/*
void	pipex_child(int fd[2], int argc, char **argv, char **envp)
{
	int		idx;
	int		in;
	char	**path;
	char	**cmd;
	char	*execve_path;

	if (dup2(fd[1], 1) < 0)
		pipex_dup2_error();
	close(fd[1]);
	in = open(argv[1], O_RDONLY);
	if (in < 0)
		pipex_open_error();
	if (dup2(in, 0) < 0)
		pipex_dup2_error();
	pipex_get_path_n_cmd(&path, &cmd, argv, envp);
	idx = 0;
	while (path[idx] != 0)
	{
		execve_path = pipex_set_path(idx++, path, cmd);
		execve(execve_path, cmd, envp);
		ft_free_ptr(&execve_path);
	}
	pipex_child_err(path, cmd, in);
}
*/