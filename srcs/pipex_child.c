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

void	pipex_child(int fd[2], int argc, char **argv, char **envp)
{
	int		i;
	int		in;
	char	**absolute_path;
	char	**cmd;
	char	*execve_path;

	//dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	in = open(argv[1], O_RDONLY);
	if (in < 0)
		pipex_open_error(in);
	pipex_get_path_n_cmd(&absolute_path, &cmd, argv, envp);
	i = 0;
	while (absolute_path[i] != 0)
	{
		execve_path = pipex_set_path(i++, absolute_path, cmd);
		execve(execve_path, cmd, envp);
		ft_free_ptr(&execve_path);
	}
	ft_free_split(absolute_path);
	ft_free_split(cmd);
	perror("execve");
	exit(-1);
}
