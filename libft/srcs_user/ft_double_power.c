/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:18:56 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 19:18:56 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_double_power(double n, int pow)
{
	if (pow == 0)
		return (1);
	else if (pow > 0)
		return (n * ft_double_power(n, pow - 1));
	else if (pow < 0)
		return (ft_double_power(n, pow + 1) / n);
	return (0);
}
