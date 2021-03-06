/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:57:19 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 10:34:26 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char const *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(&str[i]));
		i++;
	}
	if (str[i] == c)
		return ((char *)(&str[i]));
	return (0);
}
