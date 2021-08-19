/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:53:44 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_put_num(unsigned int n, char *temp, int idx)
{
	temp[idx] = 0;
	idx--;
	if (n == 0)
		temp[idx] = '0';
	else
	{
		while (idx >= 0 && n)
		{
			temp[idx] = n % 10 + '0';
			idx--;
			n /= 10;
		}
	}
}

static int	ft_calc_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

static char	*ft_itoa_ret(int num, int is_negative)
{
	int		len;
	char	*tmp;

	len = ft_calc_len(num);
	if (is_negative < 0)
	{
		tmp = (char *)malloc(sizeof(char) * (len + 2));
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '-';
		ft_put_num(num, tmp, len + 1);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp == NULL)
			return (NULL);
		ft_put_num(num, tmp, len);
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	int				is_negative;
	unsigned int	num;

	is_negative = 1;
	if (n < 0)
		is_negative = -1;
	num = n * is_negative;
	return (ft_itoa_ret(num, is_negative));
}
