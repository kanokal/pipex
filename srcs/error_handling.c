/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:27:43 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/03 20:01:47 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex_error_handling(const char *per_msg, const char *err_msg, int **fd)
{
	if (fd != NULL)
		ft_free_2d_i(fd);
	if (per_msg != NULL)
		perror(per_msg);
	if (err_msg != NULL)
		write(2, err_msg, ft_strlen(err_msg));
	exit(1);
}
