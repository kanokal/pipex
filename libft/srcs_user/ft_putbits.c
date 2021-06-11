/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:21:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/22 23:35:26 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putbits(long long n, unsigned long size)
{
	char	*str;

	size *= 8;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (-2);
	str[size] = 0;
	ft_memset(str, '0', size);
	while (size > 0)
	{
		if ((n & 0b1) == 1)
			str[size - 1] = '1';
		n = n >> 1;
		size--;
	}
	size = (unsigned long)write(1, str, ft_strlen(str));
	free(str);
	str = NULL;
	return (size);
}
