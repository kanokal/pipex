/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:54:50 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:11:44 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	**pipex_create_malloc(int count)
{
	int	idx;
	int	**fd;

	fd = (int **)malloc(sizeof(int *) * (count + 1));
	if (fd == NULL)
		pipex_error_handling(NULL, "error: malloc failed\n", NULL);
	fd[count] = NULL;
	idx = 0;
	while (idx < count)
	{
		fd[idx] = (int *)malloc(sizeof(int) * 2);
		if (fd[idx] == NULL)
		{
			while (--idx >= 0)
				free(fd[idx]);
			free(fd);
			pipex_error_handling(NULL, "error: malloc failed\n", NULL);
		}
		idx++;
	}
	return (fd);
}

int	**pipex_create_pipe(int count)
{
	int	idx;
	int	**fd;

	fd = pipex_create_malloc(count);
	idx = 0;
	while (idx < count)
	{
		if (pipe(fd[idx]) < 0)
			pipex_error_handling("pipe", NULL, fd);
		idx++;
	}
	return (fd);
}
