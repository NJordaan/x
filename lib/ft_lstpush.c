/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:27:41 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/14 12:37:02 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **root, void *content, size_t size)
{
	t_list *l;

	l = ft_lstnew(content, size);
	ft_lstadd(root, l);
}
