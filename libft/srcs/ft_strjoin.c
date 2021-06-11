/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:54:30 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	idx;
	size_t	j;

	idx = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((temp = (char *)malloc(sizeof(char) * idx)) == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		temp[idx] = s1[idx];
		idx++;
	}
	j = 0;
	while (s2[j])
	{
		temp[idx + j] = s2[j];
		j++;
	}
	temp[idx + j] = 0;
	return (temp);
}
