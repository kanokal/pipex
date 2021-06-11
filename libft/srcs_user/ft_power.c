/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:07:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/11 20:35:36 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_power(int n, int pow)
{
	if (pow == 0)
		return (1);
	else if (pow > 0)
		return (n * ft_power(n, pow - 1));
	else if (pow < 0)
		return (ft_power(n, pow + 1) / n);
	return (0);
}
