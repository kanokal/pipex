/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:01:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_child_do(t_pipex var, int **fd)
{
	char	**cmd;
	char	*execve_path;

	execve_path = pipex_get_execve_path(var, &cmd, fd);
	execve(execve_path, cmd, var.envp);
	ft_free_2d_c(cmd);
	pipex_error_handling(NULL, "execve: invalid command\n", fd);
}

void	pipex_child(t_pipex var, int **fd)
{
	if (dup2(var.fd[0], 0) < 0)
		pipex_error_handling("dup2", NULL, fd);
	if (dup2(var.fd[1], 1) < 0)
		pipex_error_handling("dup2", NULL, fd);
	close(var.fd[0]);
	close(var.fd[1]);
	return (pipex_child_do(var, fd));
}
