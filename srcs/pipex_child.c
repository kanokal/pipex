/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 17:09:51 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_child_do(t_pipex var)
{
	int		idx;
	char	**path;
	char	**cmd;
	char	*execve_path;

	pipex_get_path_n_cmd(&path, &cmd, var);
	if (ft_strlen(cmd[0]) == 0)
		ft_error_handling("error: some cmds are empty\n");
	idx = 0;
	while (path[idx] != 0)
	{
		execve_path = pipex_set_path(idx++, path, cmd);
		if (access(execve_path, F_OK) == 0)
			execve(execve_path, cmd, var.envp);
		ft_free_ptr(&execve_path);
	}
	ft_error_handling("execve: invalid command\n");
}

void	pipex_child(t_pipex var)
{
	if (dup2(var.fd[0], 0) < 0)
		pipex_dup2_error();
	if (dup2(var.fd[1], 1) < 0)
		pipex_dup2_error();
	close(var.fd[0]);
	close(var.fd[1]);
	return (pipex_child_do(var));
}
