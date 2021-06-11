/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:19:53 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/22 19:30:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_bigint_to_a_get_2(t_bigint *dst, int idx, char *str)
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

static char	*ft_bigint_to_a_get(t_bigint *dst)
{
	char	*str;
	char	*tmp;
	int		idx;

	idx = (int)dst->len - 1;
	str = ft_itoa(dst->bigint[idx]);
	if (str == NULL)
		return (NULL);
	idx--;
	while (idx >= 0)
	{
		tmp = ft_bigint_to_a_get_2(dst, idx, str);
		if (tmp == NULL)
			return (ft_free_ptr(&str));
		str = tmp;
		idx--;
	}
	return (str);
}

char		*ft_bigint_to_a(t_bigint *dst)
{
	char	*str;

	str = ft_bigint_to_a_get(dst);
	if (str == NULL)
		return (NULL);
	return (str);
}
