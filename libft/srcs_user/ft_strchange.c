/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:12:29 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/07 16:13:19 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strchange(char *str, char dst, char src)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == dst)
			str[idx] = src;
		idx++;
	}
}
