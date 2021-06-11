/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:51:25 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/22 19:16:25 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_bigint_putstr_set(t_bigint *dst, int idx, char *str)
{
	char	*tmp;
	char	*join;
	char	*zero_str;

	tmp = ft_itoa(dst->bigint[idx]);
	if (tmp == NULL)
		return (NULL);
	zero_str = ft_strjoin("00000000", tmp);
	if (zero_str == NULL)
		return (ft_free_ptr(&tmp));
	join = zero_str + ft_strlen(tmp);
	ft_free_ptr(&tmp);
	tmp = ft_strjoin(str, join);
	ft_free_ptr(&zero_str);
	ft_free_ptr(&str);
	return (tmp);
}

static int	ft_bigint_putdec(t_bigint *dst)
{
	char	*str;
	char	*tmp;
	int		idx;

	idx = (int)(dst->len - 1);
	str = ft_itoa(dst->bigint[idx]);
	if (str == NULL)
		return (-2);
	idx--;
	while (idx >= 0)
	{
		tmp = ft_bigint_putstr_set(dst, idx, str);
		if (tmp == NULL)
			return (ft_free_int(&str));
		str = tmp;
		idx--;
	}
	write(1, str + 1, ft_strlen(str + 1));
	ft_free_int(&str);
	return (0);
}

int			ft_bigint_putstr(t_bigint *dst, int is_dec)
{
	char	*str;
	char	*tmp;
	int		idx;

	if (is_dec != 0)
		return (ft_bigint_putdec(dst));
	idx = (int)dst->len - 1;
	str = ft_itoa(dst->bigint[idx]);
	if (str == NULL)
		return (-2);
	idx--;
	while (idx >= 0)
	{
		tmp = ft_bigint_putstr_set(dst, idx, str);
		if (tmp == NULL)
			return (ft_free_int(&str));
		str = tmp;
		idx--;
	}
	write(1, str, ft_strlen(str));
	ft_free_int(&str);
	return (0);
}
