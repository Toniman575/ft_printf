/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:48:22 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 15:58:11 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (first == NULL)
	{
		ft_lstdelone(first, del);
		return (NULL);
	}
	current = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current->next = ft_lstnew(f(lst->content));
		current = current->next;
		if (current == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
	}
	current->next = NULL;
	return (first);
}
