/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:33:57 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 10:05:24 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if (s && f)
	{
		i = 0;
		ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!ret)
			return (0);
		while (s[i] != '\0')
		{
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
