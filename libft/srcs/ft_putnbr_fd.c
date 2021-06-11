/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:54:12 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_put_str(int fd, char *tmp, int is_negative, int idx)
{
	if (is_negative == -1)
		tmp[idx++] = '-';
	if (idx > 0)
		idx--;
	while (idx >= 0)
	{
		write(fd, &tmp[idx], 1);
		idx--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char			tmp[13];
	unsigned int	num;
	int				is_negative;
	int				idx;

	ft_bzero(tmp, 13);
	is_negative = 1;
	if (n < 0)
	{
		is_negative = -1;
		num = (n * -1);
	}
	else
		num = n;
	if (n == 0)
		tmp[0] = '0';
	idx = 0;
	while (num != 0)
	{
		tmp[idx] = '0' + (num % 10);
		num /= 10;
		idx++;
	}
	ft_put_str(fd, tmp, is_negative, idx);
}
