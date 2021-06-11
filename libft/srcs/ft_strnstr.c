/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:54:58 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;

	if (haystack == NULL)
		return (NULL);
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] && idx < len)
	{
		if ((len - idx) < ft_strlen(needle))
			return (NULL);
		if (ft_memcmp(haystack + idx, needle, ft_strlen(needle)) == 0)
			return ((char *)(haystack + idx));
		idx++;
	}
	return (NULL);
}
