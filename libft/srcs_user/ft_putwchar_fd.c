/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd_jpyo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:35:47 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/29 01:35:47 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_putwchar_4bytes(wint_t c, int fd)
{
	unsigned char	buf[4];

	buf[0] = (c >> 18) | 0b11110000;
	buf[1] = ((c >> 12) & 0b111111) | 0b10000000;
	buf[2] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[3] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 4));
}

static int	ft_putwchar_3bytes(wint_t c, int fd)
{
	unsigned char	buf[3];

	buf[0] = (c >> 12) | 0b11100000;
	buf[1] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[2] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 3));
}

static int	ft_putwchar_2bytes(wint_t c, int fd)
{
	unsigned char	buf[2];

	buf[0] = (c >> 6) | 0b11000000;
	buf[1] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 2));
}

/*
** ------------------------------- UTF-8 -------------------------------
** 1byte = 0xxxxxxx
** 2byte = 110xxxxx 10xxxxxx
** 3byte = 1110xxxx 10xxxxxx 10xxxxxx
** 4byte = 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
** 5byte = 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
** 6byte = 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

int			ft_putwchar_fd(wint_t c, int fd)
{
	if (fd < 0)
		return (-1);
	if (c < 128)
		return (write(fd, &c, 1));
	else if (c < 2048)
		return (ft_putwchar_2bytes(c, fd));
	else if (c < 65536)
		return (ft_putwchar_3bytes(c, fd));
	else if (c < 2097152)
		return (ft_putwchar_4bytes(c, fd));
	return (-1);
}
