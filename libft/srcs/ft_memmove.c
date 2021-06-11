/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:53:59 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	idx;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (dst > src)
	{
		idx = (int)len - 1;
		while (idx >= 0)
		{
			*(char *)(dst + idx) = *(char *)(src + idx);
			idx--;
		}
	}
	else
	{
		idx = 0;
		while (idx < (int)len)
		{
			*(char *)(dst + idx) = *(char *)(src + idx);
			idx++;
		}
	}
	return (dst);
}
