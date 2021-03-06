/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:42:46 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:12:55 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	pipex_struct_set(t_pipex *var, char **argv, char **envp)
{
	var->argv = argv;
	var->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	if (argc == 5)
	{
		pipex_struct_set(&var, argv, envp);
		var.infile = argv[1];
		var.outfile = argv[argc - 1];
		var.cur = 2;
		var.cmd_count = argc - 3;
		pipex_fork(var);
	}
	else
		pipex_error_handling(NULL, "error: need 5 arguments\n", NULL);
	return (0);
}
