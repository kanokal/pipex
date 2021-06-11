/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:34:49 by jpyo              #+#    #+#             */
/*   Updated: 2021/03/22 21:15:31 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bigint_delete(t_bigint **src)
{
	free((*src)->bigint);
	(*src)->bigint = NULL;
	free(*src);
	*src = NULL;
	return (NULL);
}

int		ft_bigint_delete_int(t_bigint **src, int err)
{
	free((*src)->bigint);
	(*src)->bigint = NULL;
	free(*src);
	*src = NULL;
	return (err);
}
