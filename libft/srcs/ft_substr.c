/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:55:07 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	idx;

	if (s == NULL || ft_strlen(s) < (size_t)start)
	{
		if ((temp = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
		*temp = 0;
		return (temp);
	}
	if ((temp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		*(temp + idx) = *(s + start + idx);
		idx++;
	}
	temp[idx] = 0;
	return (temp);
}
