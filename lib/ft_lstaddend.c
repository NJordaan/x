/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:38:29 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/14 12:40:02 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **root, t_list *new)
{
	t_list *temp;

	if (*root)
	{
		temp = *root;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
	{
		*root = new;
	}
}
