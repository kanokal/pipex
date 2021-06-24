/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:42:46 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 19:50:22 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_struct_set(t_pipex *var, char **argv, char **envp)
{
	var->argv = argv;
	var->envp = envp;
}

int			main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	pipex_struct_set(&var, argv, envp);
	if (argc > 4)
	{
		if (argc > 5 && ft_strncmp(argv[1], "here_doc", 9) == 0)
		{
			var.cur = 3;
			var.cmd_count = argc - 4;
			pipex_here_doc(var);
		}
		else
		{
			var.cur = 2;
			var.cmd_count = argc - 3;
			pipex_fork(var);
		}
	}
	return (0);
}
