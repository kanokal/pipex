/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:54:50 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 16:55:04 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_set_cmd_del(char *start, char del)
{
	char	*end;

	end = ft_strchr(start + 1, del);
	*end = 0;
	ft_strdelchr(start + 1, ' ');
	*start = ' ';
	while (start != end)
	{
		if (*start == 0)
			*start = ' ';
		start++;
	}
	*end = ' ';
}

static char	**pipex_set_cmd(t_pipex var)
{
	char	*start;
	char	**tmp;

	start = ft_strchr(var.argv[var.cur], '\'');
	if (start != NULL)
		pipex_set_cmd_del(start, '\'');
	tmp = ft_split(var.argv[var.cur], ' ');
	if (tmp == NULL)
		ft_error_handling("error: malloc failed\n");
	return (tmp);
}

void	pipex_get_path_n_cmd(char ***path, char ***cmd, t_pipex var)
{
	*path = pipex_get_path(var.envp);
	if (*path == NULL)
		ft_error_handling("error: malloc failed\n");
	*cmd = pipex_set_cmd(var);
}
