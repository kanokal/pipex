/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounds_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:18:34 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 19:18:34 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_rounds_dbl(double n, int point)
{
	double	tmp;
	double	num;
	int		pow;

	tmp = n;
	pow = 0;
	while (tmp >= 10.0)
	{
		pow++;
		tmp /= 10;
	}
	num = n;
	while (pow > point)
	{
		tmp = num / ft_double_power(10.0, pow);
		num -= (int)tmp * ft_double_power(10.0, pow--);
	}
	tmp = (int)(num / ft_double_power(10.0, pow));
	if (tmp >= 5)
	{
		n += ft_double_power(10.0, point + 1);
		n -= tmp * ft_double_power(10.0, point);
	}
	return (n);
}
