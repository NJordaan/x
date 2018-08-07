/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:51:31 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/15 14:27:32 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (0);
	if (!content)
	{
		l->content = 0;
		l->content_size = 0;
	}
	else
	{
		l->content = malloc(content_size);
		if (!(l->content))
			return (0);
		ft_memcpy((l->content), content, content_size);
		l->content_size = content_size;
	}
	l->next = 0;
	return (l);
}
