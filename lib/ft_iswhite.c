/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:04:12 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/28 12:07:56 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhite(int c)
{
	if (c == '\n' ||
			c == '\t' ||
			c == ' ' ||
			c == '\r' ||
			c == '\v' ||
			c == '\f')
		return (1);
	return (0);
}