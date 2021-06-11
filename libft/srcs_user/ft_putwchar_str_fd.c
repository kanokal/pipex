/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwc_str_fd_jpyo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:31:07 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/29 02:31:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putwchar_str_fd(wchar_t *str, int fd, int size)
{
	int	len;
	int	idx;
	int is_err;

	len = 0;
	idx = 0;
	while (idx < size && str[idx] != 0)
	{
		if ((is_err = ft_putwchar_fd(str[idx], fd)) < 0)
			return (-1);
		len += is_err;
		idx++;
	}
	return (len);
}
