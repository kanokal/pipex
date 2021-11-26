/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:53:53 by jpyo              #+#    #+#             */
/*   Updated: 2021/11/27 01:18:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char *)(s1 + idx) != *(unsigned char *)(s2 + idx))
		{
			return (*(unsigned char *)(s1 + idx)
				- *(unsigned char *)(s2 + idx));
		}
		idx++;
	}
	return (0);
}
