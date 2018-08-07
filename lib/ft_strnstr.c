/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:23:00 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 10:45:49 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(str || find))
		return (0);
	if (find[0] == '\0')
		return ((char *)(str));
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == find[0])
		{
			while (str[i + j] != '\0' && find[j] != '\0' && i + j < len)
			{
				if (str[i + j] != find[j])
					break ;
				j++;
			}
			if (find[j] == '\0')
				return ((char *)(&str[i]));
		}
		i++;
	}
	return (0);
}
