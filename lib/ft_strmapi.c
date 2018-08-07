/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:46:11 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/13 16:24:32 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ret[i] = f(i, s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
