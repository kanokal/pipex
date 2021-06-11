/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_mult_val.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:23:13 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/30 01:38:27 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_bigint_mult_val(t_bigint *dst, unsigned int val)
{
	unsigned int	idx;
	unsigned int	len;

	if (val > 10)
		return (-1);
	idx = 0;
	len = dst->len;
	while (idx < len)
	{
		dst->bigint[idx] *= val;
		idx++;
	}
	idx = 0;
	while (idx < len)
	{
		if (dst->bigint[idx] >= 100000000)
		{
			val = dst->bigint[idx] / 100000000;
			dst->bigint[idx] -= (val * 100000000);
			if (ft_bigint_add_val(dst, val, idx + 1) < 0)
				return (-2);
		}
		idx++;
	}
	return (0);
}
