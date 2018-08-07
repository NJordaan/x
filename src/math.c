/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:38:06 by njordaan          #+#    #+#             */
/*   Updated: 2018/07/19 15:32:20 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

int round_to_int(float x)
{
	int val;

	val = (int)(x + 0.5);
	return (val);
}

int		ceil_to_int(float x)
{
	int val;

	val = (int)(x);
	val++;
	return (val);
}

float	square_root(int x) {
	float x1;
	float x2;

	x1 = (x * 1.0) / 2;
	x2 = (x1 + (x / x1)) / 2;
	while (ft_abs(x1 - x2) >= 0.0000001)
	{
		x1 = x2;
		x2 = (x1 + (x / x1)) / 2;
	}
	return (x2);
}
