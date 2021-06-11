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

char		*ft_itoa(int n)
{
	int				is_negative;
	int				len;
	unsigned int	num;
	char			*tmp;

	is_negative = 1;
	if (n < 0)
		is_negative = -1;
	num = n * is_negative;
	len = ft_calc_len(num);
	if (is_negative < 0)
	{
		if ((tmp = (char *)malloc(sizeof(char) * (len + 2))) == NULL)
			return (NULL);
		tmp[0] = '-';
		ft_put_num(num, tmp, len + 1);
	}
	else
	{
		if ((tmp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_put_num(num, tmp, len);
	}
	return (tmp);
}
