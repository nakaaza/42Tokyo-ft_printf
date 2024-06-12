/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:45:03 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/20 19:33:55 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*res;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst -> content));
	if (!new_lst)
		return (NULL);
	res = new_lst;
	lst = lst -> next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst -> content));
		if (!new_node)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		new_lst -> next = new_node;
		new_lst = new_lst -> next;
		lst = lst -> next;
	}
	return (res);
}
