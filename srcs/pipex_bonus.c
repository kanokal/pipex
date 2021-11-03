/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:42:46 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:12:49 by jpyo             ###   ########.fr       */
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

	if (argc > 4)
	{
		pipex_struct_set(&var, argv, envp);
		var.infile = argv[1];
		var.outfile = argv[argc - 1];
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
	else
		pipex_error_handling(NULL, "error: need more than 4 arguments\n", NULL);
	return (0);
}
