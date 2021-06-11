/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:44:39 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 21:33:44 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_dbl	*ft_dtob_3(t_dbl *dbl, long long bits, int exp)
{
	long long	dec;

	dbl->decimal = ft_bigint_create(1);
	if (dbl->decimal == NULL)
		return (ft_dbl_delete(&dbl));
	dbl->integer = ft_bigint_create(1);
	if (dbl->integer == NULL)
		return (ft_dbl_delete(&dbl));
	dec = (bits & 0xfffffffffffff) + 0x10000000000000;
	if (ft_binary_to_bigint(dbl->decimal, dec, 1, 52 + exp))
		return (ft_dbl_delete(&dbl));
	return (dbl);
}

static t_dbl	*ft_dtob_2(t_dbl *dbl, long long bits, int exp)
{
	long long	integer;
	long long	dec;

	dbl->decimal = ft_bigint_create(1);
	if (dbl->decimal == NULL)
		return (ft_dbl_delete(&dbl));
	dbl->integer = ft_bigint_create(1);
	if (dbl->integer == NULL)
		return (ft_dbl_delete(&dbl));
	bits = (bits & 0xfffffffffffff) + 0x10000000000000;
	dec = (bits & (0xfffffffffffff >> exp)) + (0x10000000000000 >> exp);
	integer = (bits >> (52 - exp)) & ((2 << exp) - 1);
	if (ft_binary_to_bigint(dbl->integer, integer, 0, 0) < 0)
		return (ft_dbl_delete(&dbl));
	if (ft_binary_to_bigint(dbl->decimal, dec, 1, 52 - exp) < 0)
		return (ft_dbl_delete(&dbl));
	return (dbl);
}

static t_dbl	*ft_dtob_1(t_dbl *dbl, long long bits, int exp)
{
	dbl->decimal = ft_bigint_create(1);
	if (dbl->decimal == NULL)
		return (ft_dbl_delete(&dbl));
	dbl->integer = ft_bigint_create(1);
	if (dbl->integer == NULL)
		return (ft_dbl_delete(&dbl));
	bits = (bits & 0xfffffffffffff) + 0x10000000000000;
	if (ft_binary_to_bigint(dbl->integer, bits, 0, 0) < 0)
		return (ft_dbl_delete(&dbl));
	if (ft_binary_to_bigint(dbl->decimal, 1, 1, 0) < 0)
		return (ft_dbl_delete(&dbl));
	exp -= 52;
	while (exp > 0)
	{
		if (ft_bigint_mult_val(dbl->integer, 2) < 0)
			return (ft_dbl_delete(&dbl));
		exp--;
	}
	return (dbl);
}

static t_dbl	*ft_dtob_0(t_dbl *dbl)
{
	dbl->decimal = ft_bigint_create(1);
	if (dbl->decimal == NULL)
		return (ft_dbl_delete(&dbl));
	dbl->decimal->bigint[0] = 10;
	dbl->integer = ft_bigint_create(1);
	if (dbl->integer == NULL)
		return (ft_dbl_delete(&dbl));
	return (dbl);
}

t_dbl			*ft_dtob(double n)
{
	long long	*bits;
	t_dbl		*dbl;
	int			exp;

	dbl = ft_dbl_create();
	if (dbl == NULL)
		return (NULL);
	bits = (long long *)&n;
	dbl->sign = (int)(*bits >> 63);
	*bits = *bits & 0x7fffffffffffffff;
	exp = ((*bits >> 52) & 0x7ff) - 1023;
	if (*bits == 0)
		return (ft_dtob_0(dbl));
	else if (exp >= 52)
		return (ft_dtob_1(dbl, *bits, exp));
	else if (exp < 52 && exp >= 0)
		return (ft_dtob_2(dbl, *bits, exp));
	else if (exp < 0)
		return (ft_dtob_3(dbl, *bits, -exp));
	return (ft_dbl_delete(&dbl));
}
