/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:20:15 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/30 19:20:15 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_rev_str(char *str)
{
	size_t	idx;
	size_t	len;
	char	tmp;

	idx = 0;
	len = ft_strlen(str);
	while (idx < len / 2)
	{
		tmp = *(str + idx);
		*(str + idx) = *(str + len - idx - 1);
		*(str + len - idx - 1) = tmp;
		idx++;
	}
}
