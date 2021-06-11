/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:04:06 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/23 00:39:13 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_dtoa_free(t_dbl **dbl, char **s1, char **s2)
{
	ft_dbl_delete(dbl);
	if (*s1 != NULL)
		ft_free_ptr(s1);
	if (*s2 != NULL)
		ft_free_ptr(s2);
	return (NULL);
}

char		*ft_dtoa(double n)
{
	t_dbl	*dbl;
	char	*integer;
	char	*decimal;
	char	*str;

	dbl = ft_dtob(n);
	if (dbl == NULL)
		return (NULL);
	integer = ft_bigint_to_a(dbl->integer);
	if (integer == NULL)
		return (ft_dbl_delete(&dbl));
	decimal = ft_bigint_to_a(dbl->decimal);
	if (decimal == NULL)
		return (ft_dtoa_free(&dbl, &integer, NULL));
	decimal[0] = '.';
	str = ft_strjoin(integer, decimal);
	ft_dtoa_free(&dbl, &integer, &decimal);
	return (str);
}
