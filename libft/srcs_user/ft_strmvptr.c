/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmvptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:32:43 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 22:34:49 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmvptr(char *ptr, const char *s)
{
	if (ptr == NULL)
		return (NULL);
	if (s == NULL)
		return (ptr);
	while (*ptr != 0 && ft_strchr(s, *ptr) != NULL)
		ptr++;
	return (ptr);
}
