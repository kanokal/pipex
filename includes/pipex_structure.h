/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:12:18 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/12 22:11:22 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTURE_H
# define PIPEX_STRUCTURE_H

typedef struct	s_pipex
{
	int			fd[2];
	int			cur;
	int			last;
	char		**argv;
	char		**envp;
}				t_pipex;

#endif