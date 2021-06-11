/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_bigint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:14:48 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/31 03:16:03 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_bitob_dec_process(t_bigint *dst, int length, int idx)
{
	int			j;
	t_bigint	*val;

	val = ft_bigint_power(5, length - idx);
	if (val == NULL)
		return (-2);
	j = 1;
	while (j++ < idx + 1)
		if (ft_bigint_mult_val(val, 10) < 0)
			return (ft_bigint_delete_int(&val, -2));
	if (ft_bigint_add(dst, val) < 0)
		return (ft_bigint_delete_int(&val, -2));
	ft_bigint_delete(&val);
	return (0);
}

static int	ft_bitob_dec(t_bigint *dst, long long bits, int length)
{
	int	idx;

	if (length <= 0)
	{
		dst->bigint[0] = 10;
		return (0);
	}
	dst->bigint[0] = 1;
	idx = 1;
	while (idx++ < length + 1)
		if (ft_bigint_mult_val(dst, 10) < 0)
			return (-2);
	idx = 0;
	while (idx < length)
	{
		if (bits & 1)
			if (ft_bitob_dec_process(dst, length, idx) < 0)
				return (-2);
		idx++;
		bits = bits >> 1;
	}
	return (0);
}

static int	ft_bitob_int(t_bigint *dst, long long bits, int length)
{
	int			idx;
	t_bigint	*val;

	idx = 0;
	while (idx < length)
	{
		if (bits & 1)
		{
			val = ft_bigint_power(2, idx);
			if (val == NULL)
				return (-2);
			if (ft_bigint_add(dst, val) < 0)
				return (-2);
			ft_bigint_delete(&val);
		}
		idx++;
		bits = bits >> 1;
	}
	return (0);
}

static int	ft_bitob_set(long long *bits, int is_dec, int *dec_length)
{
	int			length;
	int			start_bits;
	int			idx;
	long long	tmp;

	idx = sizeof(long long) * 8;
	while (is_dec != 0 && idx > 0)
	{
		if (*bits & 1)
			break ;
		idx--;
		(*dec_length)--;
		*bits = *bits >> 1;
	}
	tmp = *bits;
	length = 1;
	while (length <= idx)
	{
		if (tmp & 1)
			start_bits = length;
		length++;
		tmp = tmp >> 1;
	}
	return (start_bits);
}

int			ft_binary_to_bigint(t_bigint *dst, long long bits,
									int is_dec, int dec_length)
{
	int				start_bits;
	unsigned int	idx;

	start_bits = ft_bitob_set(&bits, is_dec, &dec_length);
	idx = 0;
	while (idx < dst->len)
		dst->bigint[idx++] = 0;
	if (is_dec == 0)
		return (ft_bitob_int(dst, bits, start_bits));
	else
		return (ft_bitob_dec(dst, bits, dec_length));
}
