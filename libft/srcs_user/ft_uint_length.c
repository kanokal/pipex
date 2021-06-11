/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:16:38 by jpyo              #+#    #+#             */
/*   Updated: 2021/02/02 21:13:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Calculate the number of digits in base.
*/

size_t	ft_uint_length(unsigned int n, int base_length)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / base_length;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}
