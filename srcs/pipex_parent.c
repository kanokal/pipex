/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:18:44 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 17:30:42 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
** wait 함수 리턴값 확인
** fork 했을때 처음부터인지 아닌지 체크
*/

static void	pipex_parent_err(char **path, char**cmd, int out)
{
	ft_free_split(path);
	ft_free_split(cmd);
	close(out);
	perror("execve");
	exit(-1);
}

void	pipex_parent(int fd[2], int argc, char **argv, char **envp)
{
	int		idx;
	int		out;
	char	**path;
	char	**cmd;
	char	*execve_path;

	wait(0);
	if (dup2(fd[0], 0) < 0)
		pipex_dup2_error();
	close(fd[0]);
	close(fd[1]);
	out = open("outfile", O_WRONLY | O_CREAT | O_TRUNC);
	if (out < 0)
		pipex_open_error();
	if (dup2(out, 1) < 0)
		pipex_dup2_error();
	pipex_get_path_n_cmd(&path, &cmd, argv, envp);
	idx = 0;
	while (path[idx] != 0)
	{
		execve_path = pipex_set_path(idx++, path, cmd);
		execve(execve_path, cmd, envp);
		ft_free_ptr(&execve_path);
	}
	return (pipex_parent_err(path, cmd, out));
}