/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:00:28 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 23:10:35 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_atod2(char *str)
{
	double	integer;
	double	decimal;
	int		idx;

	integer = (double)ft_atol2(str);
	str = ft_strmvptr(str, ".");
	decimal = 0.0;
	idx = 1;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		decimal += (double)(*str - '0') / ft_double_power(10.0, idx++);
		str++;
	}
	if (integer < 0.0)
		return (integer - decimal);
	return (integer + decimal);
}
