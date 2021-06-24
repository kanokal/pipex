/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:34:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 20:06:26 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*pipex_set_path(int i, char **absolute_path, char **cmd)
{
	char	*path;
	char	*execve_path;

	path = ft_strjoin(absolute_path[i], "/");
	if (path == NULL)
		ft_error_handling("error: malloc failed\n");
	execve_path = ft_strjoin(path, cmd[0]);
	ft_free_ptr(&path);
	if (execve_path == NULL)
		ft_error_handling("error: malloc failed\n");
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
			break ;
		i++;
	}
	split = ft_split(envp[i] + 5, ':');
	if (split == NULL)
		return (NULL);
	return (split);
}

void	pipex_get_path_n_cmd(char ***path, char ***cmd, t_pipex var)
{
	*path = pipex_get_path(var.envp);
	if (*path == NULL)
		ft_error_handling("error: malloc failed\n");
	*cmd = ft_split(var.argv[var.cur], ' ');
	if (*cmd == NULL)
		ft_error_handling("error: malloc failed\n");
}
