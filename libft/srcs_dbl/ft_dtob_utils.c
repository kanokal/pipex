/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtob_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:13:58 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 21:34:01 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_dbl_delete(t_dbl **dst)
{
	if ((*dst)->integer != NULL)
		ft_bigint_delete(&((*dst)->integer));
	if ((*dst)->decimal != NULL)
		ft_bigint_delete(&((*dst)->decimal));
	free(*dst);
	*dst = NULL;
	return (NULL);
}

t_dbl	*ft_dbl_create(void)
{
	t_dbl	*dbl;

	dbl = (t_dbl *)malloc(sizeof(t_dbl));
	if (dbl == NULL)
		return (NULL);
	dbl->integer = NULL;
	dbl->decimal = NULL;
	dbl->sign = 0;
	return (dbl);
}
