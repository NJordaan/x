/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:49:36 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/29 11:02:03 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int i;

	i = 1;
	if (n <= -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n >= 2147483647)
	{
		ft_putstr("2147483647");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	while (i <= n / 10)
		i *= 10;
	while (i)
	{
		ft_putchar('0' + n / i % 10);
		i /= 10;
	}
}