/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:12:18 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 17:03:50 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTURE_H
# define PIPEX_STRUCTURE_H

typedef struct	s_pipex
{
	int			fd[2];
	int			cur;
	int			cmd_count;
	char		**argv;
	char		**envp;
	char		*infile;
	char		*outfile;
}				t_pipex;

#endif
