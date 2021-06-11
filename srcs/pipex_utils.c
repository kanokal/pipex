/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:34:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 18:40:04 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex_get_path_n_cmd(char ***path, char ***cmd, char **argv, char **envp)
{
	*path = pipex_get_path(envp);
	if (*path == NULL)
		pipex_malloc_error(NULL, NULL, NULL, NULL);
	*cmd = ft_split(argv[2], ' ');
	if (*cmd == NULL)
		pipex_malloc_error(NULL, NULL, *path, NULL);
}

char	*pipex_set_path(int i, char **absolute_path, char **cmd)
{
	char	*path;
	char	*execve_path;

	path = ft_strjoin(absolute_path[i], "/");
	if (path == NULL)
		pipex_malloc_error(NULL, NULL, absolute_path, cmd);
	execve_path = ft_strjoin(path, cmd[0]);
	ft_free_ptr(&path);
	if (execve_path == NULL)
		pipex_malloc_error(NULL, NULL, absolute_path, cmd);
	return (execve_path);
}

char	**pipex_get_path(char **envp)
{
	int		i;
	char	**split;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break;
		i++;
	}
	split = ft_split(envp[i] + 5, ':');
	if (split == NULL)
		return (NULL);
	return (split);
}
