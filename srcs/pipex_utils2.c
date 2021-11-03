/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:54:50 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:01:41 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*pipex_get_execve_path(t_pipex var, char ***cmd, int **fd)
{
	int		idx;
	char	**path;
	char	*execve_path;

	path = pipex_get_path(var.envp);
	if (path == NULL)
		pipex_error_handling(NULL, "error: malloc failed\n", fd);
	*cmd = ft_split(var.argv[var.cur], ' ');
	if (*cmd == NULL)
	{
		ft_free_2d_c(path);
		pipex_error_handling(NULL, "error: malloc failed\n", fd);
	}
	idx = 0;
	while (path[idx] != 0)
	{
		execve_path = pipex_set_path(idx++, path, *cmd, fd);
		if (access(execve_path, F_OK) == 0)
			break ;
		ft_free_ptr(&execve_path);
	}
	ft_free_2d_c(path);
	return (execve_path);
}
