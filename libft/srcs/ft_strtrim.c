/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:55:04 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_char(char c, char const *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (c == s[idx])
			return (1);
		idx++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	idx;
	char	*temp;

	start = 0;
	while (s1[start] && ft_check_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check_char(s1[end - 1], set))
		end--;
	if ((temp = (char *)malloc(sizeof(char) * (end - start + 1))) == NULL)
		return (NULL);
	idx = 0;
	while (start < end)
	{
		temp[idx] = s1[start];
		idx++;
		start++;
	}
	temp[idx] = 0;
	return (temp);
}
