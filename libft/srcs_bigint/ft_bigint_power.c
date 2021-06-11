/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:52:03 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/27 22:14:13 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bigint	*ft_bigint_power(unsigned int n, int pow)
{
	t_bigint	*dst;

	dst = ft_bigint_create(1);
	if (dst == NULL)
		return (NULL);
	dst->bigint[0] = 1;
	while (pow-- > 0)
		ft_bigint_mult_val(dst, n);
	return (dst);
}
