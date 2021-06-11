/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_base_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:18:13 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/31 03:16:14 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_raise_end(char *str, char *base)
{
	int		i;
	int		j;
	char	*rst;

	rst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (rst == NULL)
		return (ft_free_ptr(&str));
	i = 0;
	j = 0;
	while (ft_strchr(base, str[j]) == NULL && str[j] != 0)
		rst[i++] = str[j++];
	rst[i++] = base[1];
	while (str[j] != 0)
		rst[i++] = str[j++];
	rst[i] = 0;
	ft_free_ptr(&str);
	return (rst);
}

char		*ft_raise_base_str(char *src, int point, char *base)
{
	char	*dst;

	if (src == NULL || base == NULL)
		return (NULL);
	dst = ft_strdup(src);
	if (dst == NULL)
		return (NULL);
	if (point < 0 || point >= (int)ft_strlen(dst))
		return (dst);
	while (ft_strchr(base, dst[point]) == NULL)
		point--;
	dst[point]++;
	while (ft_strchr(base, dst[point]) == NULL)
	{
		dst[point] = base[0];
		if (point == 0)
			return (ft_raise_end(dst, base));
		while (ft_strchr(base, dst[--point]) == NULL && point >= 0)
			;
		if (point < 0)
			return (ft_raise_end(dst, base));
		dst[point]++;
	}
	return (dst);
}
