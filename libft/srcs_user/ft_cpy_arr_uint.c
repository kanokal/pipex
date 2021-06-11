/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_arr_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:01 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/10 19:39:56 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_cpy_arr_uint(unsigned int *dst, unsigned int *src, unsigned int len)
{
	unsigned int	idx;

	idx = 0;
	while (idx < len)
	{
		dst[idx] = src[idx];
		idx++;
	}
}
