/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:10:21 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 18:39:17 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

void	pipex_parent(int fd[2], int argc, char **argv, char **envp);
void	pipex_child(int fd[2], int argc, char **argv, char **envp);

char	**pipex_get_path(char **envp);
char	*pipex_set_path(int i, char **absolute_path, char **cmd);
void	pipex_get_path_n_cmd(char ***path, char ***cmd, char **argv, char **envp);

void	pipex_open_error(int err);
void	pipex_malloc_error(char *s1, char *s2, char **split1, char **split2);

# include <stdio.h>

#endif