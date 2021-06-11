/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bankers_rounding_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:31:00 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/29 20:59:21 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_bankers_rounding_raise(char *str, int point)
{
	char	*tmp;
	int		idx;

	idx = point;
	while (str[idx] != 0)
	{
		if (str[idx] < '0' || str[idx] > '9')
		{
			idx++;
			continue;
		}
		str[idx] = '0';
		idx++;
	}
	tmp = ft_raise_base_str(str, point - 1, "0123456789");
	if (tmp == NULL)
		return (NULL);
	ft_free_ptr(&str);
	return (tmp);
}

static char	*ft_bankers_rounding_str_2(char *dst, int point)
{
	int		idx;

	idx = point + 1;
	while (dst[idx] != 0)
	{
		if (dst[idx] == '0')
			idx++;
		else if (dst[idx] < '0' || dst[idx] > '9')
			idx++;
		else
			break ;
	}
	if (dst[idx] != 0)
		return (ft_bankers_rounding_raise(dst, point));
	idx = point - 1;
	while ((dst[idx] < '0' || dst[idx] > '9') && idx >= 0)
		idx--;
	if (idx < 0)
		idx = 0;
	idx = dst[idx] - '0';
	if (idx % 2 == 1)
		return (ft_bankers_rounding_raise(dst, point));
	return (dst);
}

char		*ft_bankers_rounding_str(char *src, int point)
{
	char	*dst;
	int		round;

	dst = ft_strdup(src);
	if (dst == NULL)
		return (NULL);
	while (dst[point] < '0' || dst[point] > '9')
		point--;
	round = dst[point] - '0';
	if (round > 5)
		return (ft_bankers_rounding_raise(dst, point));
	else if (round == 5)
		return (ft_bankers_rounding_str_2(dst, point));
	return (dst);
}
