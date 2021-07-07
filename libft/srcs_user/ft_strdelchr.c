/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:19:55 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 15:24:26 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strdelchr(char *str, char del)
{
	int	idx;
	int	j;

	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == del)
		{
			j = idx;
			while (1)
			{
				str[j] = str[j + 1];
				if (str[j] == 0)
					break ;
				j++;
			}
			continue ;
		}
		idx++;
	}
}