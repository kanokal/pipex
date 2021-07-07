/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_xor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:32:51 by jpyo              #+#    #+#             */
/*   Updated: 2021/07/04 14:59:00 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** XOR shift random number generator
** https://namu.wiki/w/%EB%82%9C%EC%88%98%EC%83%9D%EC%84%B1#s-3.4
*/

int	ft_rand_xor(int seed1, int seed2)
{
	int x;
	int y;

	x = seed1;
	y = seed2;
	seed1 = y;
	x ^= x << 23;
	seed2 = x ^ y ^ (x >> 17) ^ (y >> 26);
	return (seed2 + y);
}
