/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:53:15 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	idx;
	int	is_negative;

	idx = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
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
