/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:06:19 by jpyo              #+#    #+#             */
/*   Updated: 2021/08/22 16:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_free_2d_c(char **arr)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == NULL)
		{
			free(arr[i]);
			break ;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	*ft_free_2d_i(int **arr)
{
	int	i;

	i = 0;
	while (1)
	{
		if (arr[i] == NULL)
		{
			free(arr[i]);
			break ;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
