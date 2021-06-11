/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_top_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:25:50 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/27 22:25:51 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_get_top_double_2(char *dtoa)
{
	int	pow;

	pow = 2;
	while (dtoa[pow] == '0')
		pow++;
	pow = -(pow - 1);
	return (pow);
}

static int	ft_get_top_double_1(char *dtoa)
{
	int	pow;

	pow = 1;
	while (dtoa[pow] != '.' && dtoa[pow] != 0)
	{
		pow++;
	}
	pow = pow - 1;
	return (pow);
}

int			ft_get_top_double(double n, char *dtoa)
{
	int	pow;

	if (n == 0)
		return (0);
	else if (n >= 1 || n <= -1)
		pow = ft_get_top_double_1(dtoa);
	else
		pow = ft_get_top_double_2(dtoa);
	return (pow);
}
