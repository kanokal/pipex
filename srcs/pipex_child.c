/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/15 21:57:28 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_child_err(char **path, char**cmd)
{
	ft_free_split(path);
	ft_free_split(cmd);
	write(2, "execve: invalid command\n", 24);
	exit(-1);
}

static void	pipex_child_do(t_pipex var, int infile)
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
	close(var.fd[1]);
	close(infile);
	return (pipex_child_err(path, cmd));
}

void		pipex_child(t_pipex var)
{
	int		infile;

	if (dup2(var.fd[1], 1) < 0)
		pipex_dup2_error(var, 1);
	infile = open(var.argv[var.cur++], O_RDONLY);
	if (infile < 0)
		pipex_open_error();
	if (dup2(infile, 0) < 0)
	{
		close(infile);
		pipex_dup2_error(var, 1);
	}
	close(var.fd[0]);
	return (pipex_child_do(var, infile));
}
