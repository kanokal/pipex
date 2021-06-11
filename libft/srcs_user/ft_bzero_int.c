/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:24:56 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/03 17:24:56 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero_int(int *arr, size_t n)
{
	size_t	idx;

	if (arr == NULL || n == 0)
		return ;
	idx = 0;
	while (idx < n)
	{
		arr[idx] = 0;
		idx++;
	}
}