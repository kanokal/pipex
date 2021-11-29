/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:10:21 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/30 06:52:08 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "pipex_structure.h"
# include "../libft/includes/libft.h"

void	pipex_fork(t_pipex var);

void	pipex_parent(t_pipex var);
void	pipex_child(t_pipex var, int **fd);

char	**pipex_get_path(char **envp);
char	*pipex_set_path(int i, char **path, char **cmd, int **fd);
char	*pipex_get_execve_path(t_pipex var, char ***cmd, int **fd);

void	pipex_error_handling(const char *per_msg, const char *err_msg,
			int **fd);
int		**pipex_create_pipe(int count);

void	pipex_here_doc(t_pipex var);

#endif
