/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:20:07 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/16 14:12:28 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	n;
	int		m;

	i = 0;
	m = 1;
	n = 0;
	while (ft_iswhite(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (long long int)(str[i] - '0');
		i++;
		if (i > 19 && m == -1)
			return (0);
		else if (i > 19)
			return (-1);
	}
	return (n * m);
}
