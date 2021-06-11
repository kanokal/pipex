/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:20:40 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 19:20:40 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_wchar_strlen(const wchar_t *str)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 128)
			len += 1;
		else if (str[idx] < 2048)
			len += 2;
		else if (str[idx] < 65536)
			len += 3;
		else if (str[idx] < 2097152)
			len += 4;
		else if (str[idx] < 16777216)
			len += 5;
		idx++;
	}
	return (len);
}
