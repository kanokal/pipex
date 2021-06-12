/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:06:19 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/10 18:06:27 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == NULL)
		{
			free(s[i]);
			break;
		}
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}