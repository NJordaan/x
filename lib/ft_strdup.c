/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:57:36 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/11 11:39:53 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *str)
{
	int		i;
	int		l;
	char	*ret;

	i = 0;
	l = 0;
	while (str[l] != '\0')
		l++;
	ret = (char *)malloc(sizeof(char) * (l + 1));
	if (ret)
	{
		while (i < l)
		{
			ret[i] = str[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
