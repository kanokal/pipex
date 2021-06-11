/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 01:58:04 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/31 01:21:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bigint	*ft_bigint_create(unsigned int idx)
{
	t_bigint		*dst;
	unsigned int	tmp;

	dst = (t_bigint *)malloc(sizeof(t_bigint));
	if (dst == NULL)
		return (NULL);
	dst->bigint = (unsigned int *)malloc(sizeof(unsigned int) * idx);
	if (dst->bigint == NULL)
	{
		free(dst);
		dst = NULL;
		return (NULL);
	}
	dst->len = idx;
	tmp = 0;
	while (tmp < idx)
		dst->bigint[tmp++] = 0;
	return (dst);
}

int			ft_bigint_cpy(t_bigint *dst, t_bigint *src)
{
	unsigned int	idx;

	idx = 0;
	while (idx < src->len)
	{
		if (idx >= dst->len)
			return (1);
		dst->bigint[idx] = src->bigint[idx];
		idx++;
	}
	return (0);
}

t_bigint	*ft_bigint_dup(t_bigint *src)
{
	t_bigint		*dst;

	dst = ft_bigint_create(src->len);
	if (dst == NULL)
		return (NULL);
	ft_bigint_cpy(dst, src);
	return (dst);
}

int			ft_bigint_increase(t_bigint *dst, unsigned int length)
{
	unsigned int	*tmp;

	if (dst->len >= length)
		length = dst->len + 1;
	tmp = (unsigned int *)malloc(sizeof(unsigned int) * length);
	if (tmp == NULL)
		return (-2);
	tmp[length - 1] = 0;
	ft_cpy_arr_uint(tmp, dst->bigint, dst->len);
	free(dst->bigint);
	dst->bigint = tmp;
	dst->len = length;
	return (0);
}
