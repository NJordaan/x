/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:19:26 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 09:38:23 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*r;
	t_list		*l;

	if (!lst)
		return (0);
	l = f(lst);
	r = l;
	while (lst->next)
	{
		lst = lst->next;
		if (!(l->next = f(lst)))
		{
			free(l->next);
			return (0);
		}
		l = l->next;
	}
	return (r);
}
