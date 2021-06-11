/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:27:01 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/20 01:08:09 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_bigint_add(t_bigint *dst, t_bigint *src)
{
	unsigned int	idx;

	if (dst->len < src->len)
		if (ft_bigint_increase(dst, src->len) < 0)
			return (-2);
	idx = 0;
	while (idx < src->len)
	{
		if (ft_bigint_add_val(dst, src->bigint[idx], idx) < 0)
			return (-2);
		idx++;
	}
	return (0);
}
