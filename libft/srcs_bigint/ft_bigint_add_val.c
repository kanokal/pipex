/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:51:23 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/30 01:53:15 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_bigint_add_val(t_bigint *dst, unsigned int val, unsigned int idx)
{
	if (dst->len <= idx)
		if (ft_bigint_increase(dst, idx + 1) < 0)
			return (-2);
	if (val >= 100000000)
	{
		ft_bigint_add_val(dst, val / 100000000, idx + 1);
		val = val % 100000000;
	}
	dst->bigint[idx] += val;
	if (dst->bigint[idx] >= 100000000)
	{
		val = dst->bigint[idx] / 100000000;
		dst->bigint[idx] -= (val * 100000000);
		return (ft_bigint_add_val(dst, val, idx + 1));
	}
	return (0);
}
