/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:59:08 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/02 14:59:08 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_quick_sort(int *arr, int arr_size)
{
	int pivot;
	int	i;
	int	j;

	if (arr_size < 2)
		return ;
	pivot = arr[arr_size - 1];
	i = 0;
	j = arr_size - 2;
	while (i <= j)
	{
		if (arr[j] > pivot)
			j--;
		else if (arr[i] <= pivot)
			i++;
		else if (arr[i] > pivot && arr[i] > arr[j])
			ft_swap(&arr[i++], &arr[j--]);
	}
	ft_swap(&arr[i], &arr[arr_size - 1]);
	ft_quick_sort(arr, i);
	ft_quick_sort(arr + i + 1, arr_size - i - 1);
}
