/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:41:07 by jpyo              #+#    #+#             */
/*   Updated: 2021/02/05 17:41:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** If c in str, return positive value
** If c not in str, return 0
** error is negative value
*/

int	ft_str_in_chr(const char *str, int c)
{
	int	idx;

	if (str == NULL)
		return (-1);
	idx = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}
