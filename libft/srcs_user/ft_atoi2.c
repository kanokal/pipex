/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:21:35 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 22:21:54 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi2(const char *str)
{
	int	result;
	int	idx;
	int	is_negative;

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
