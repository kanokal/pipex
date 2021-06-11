/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:06:17 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 18:06:17 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts a unsigned int to str according to the base.
*/

char	*ft_uint_to_str(unsigned int n, char *base)
{
	char	*str;
	int		len;
	int		base_length;

	base_length = (int)ft_strlen(base);
	len = (int)ft_uint_length(n, base_length);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (ft_free_ptr(&str));
	str[len--] = 0;
	if (n == 0)
		str[len--] = '0';
	while (len >= 0 && n)
	{
		str[len--] = base[n % base_length];
		n /= base_length;
	}
	return (str);
}
