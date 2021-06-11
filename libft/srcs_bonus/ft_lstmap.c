/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:52:58 by jpyo              #+#    #+#             */
/*   Updated: 2021/01/17 02:59:18 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start = NULL;
	temp = lst;
	while (temp)
	{
		if ((new = ft_lstnew((*f)(temp->content))) == NULL)
			ft_lstclear(&start, del);
		ft_lstadd_back(&start, new);
		temp = temp->next;
	}
	return (start);
}
