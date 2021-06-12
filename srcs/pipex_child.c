/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 18:39:35 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_child_err(char **path, char**cmd, int in)
{
	ft_free_split(path);
	ft_free_split(cmd);
	close(in);
	perror("execve");
	exit(-1);
}

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
	if (dup2(in, 0) < 0);
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
