/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:44 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 15:11:46 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/*
static void	pipex_parent_err(char **path, char**cmd)
{
	ft_free_split(path);
	ft_free_split(cmd);
	write(2, "execve: invalid command\n", 24);
	exit(-1);
}

static void	pipex_parent_do(t_pipex var, int outfile)
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
		if (access(execve_path, F_OK) != 0)
		{
			ft_free_ptr(&execve_path);
			continue;
		}
		execve(execve_path, cmd, var.envp);
	}
	close(outfile);
	close(var.fd[0]);
	return (pipex_parent_err(path, cmd));
}

void	pipex_parent(t_pipex var)
{
	int		outfile;

	if (dup2(var.fd[0], 0) < 0)
		pipex_dup2_error(var, 1);
	outfile = open(var.argv[var.last], O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile < 0)
		pipex_open_error();
	if (dup2(outfile, 1) < 0)
	{
		close(outfile);
		pipex_dup2_error(var, 0);
	}
	close(var.fd[1]);
	return (pipex_parent_do(var, outfile));
}
*/