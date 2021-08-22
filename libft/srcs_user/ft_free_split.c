/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:06:19 by jpyo              #+#    #+#             */
/*   Updated: 2021/08/22 16:52:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_free_split(void **s)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == NULL)
		{
			free(s[i]);
			break ;
		}
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
