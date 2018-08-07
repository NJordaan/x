/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:08:07 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/16 14:09:43 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s)
	{
		i = 0;
		str = (char *)malloc(len + 1);
		if (!str)
			return (0);
		while (len > 0)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
