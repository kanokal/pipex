/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:10:21 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/24 20:07:25 by jpyo             ###   ########.fr       */
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
void	pipex_child(t_pipex var);

char	**pipex_get_path(char **envp);
char	*pipex_set_path(int i, char **path, char **cmd);
void	pipex_get_path_n_cmd(char ***path, char ***cmd, t_pipex var);

void	pipex_pipe_error(void);
void	pipex_open_error(void);
void	pipex_dup2_error(void);
void	pipex_fork_error(void);
void	pipex_malloc_error(char *s1, char *s2, char **split1, char **split2);
int		**pipex_create_pipe(int count);

void	pipex_here_doc(t_pipex var);

#endif
