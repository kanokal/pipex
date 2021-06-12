/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:27:43 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 18:31:02 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex_malloc_error(char *s1, char *s2, char **split1, char **split2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (split1 != NULL)
		ft_free_split(split1);
	if (split2 != NULL)
		ft_free_split(split2);
	write(2, "error: malloc failed\n", 21);
	exit(-2);
}

void	pipex_open_error(void)
{
	perror("open");
	exit(errno);
}

void	pipex_dup2_error(void)
{
	perror("dup2");
	exit(errno);
}
