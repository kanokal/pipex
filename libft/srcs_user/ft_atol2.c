/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:18:55 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 23:02:21 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol2(const char *str)
{
	long	result;
	int		idx;
	int		is_negative;

	idx = 0;
	is_negative = 1;
	if (str[idx] == '-')
	{
		is_negative = -1;
		idx++;
	}
	else if (str[idx] == '+')
		idx++;
	result = 0;
	while ((str[idx] >= '0' && str[idx] <= '9'))
	{
		result = (result * 10) + (str[idx] - '0');
		idx++;
	}
	return (result * is_negative);
}
