/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:28:34 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 09:49:28 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	char	*d;
	char	*s;

	if (!(dst || src))
		return (0);
	d = (char *)dst;
	s = (char *)src;
	if (dst >= src)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
