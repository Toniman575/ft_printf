/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:16:21 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 10:18:02 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *add)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = add;
	else if (add != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = add;
	}
}
