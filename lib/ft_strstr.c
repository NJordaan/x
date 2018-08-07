/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:02:26 by njordaan          #+#    #+#             */
/*   Updated: 2018/05/31 10:44:58 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char const *str, char const *find)
{
	int i;
	int j;

	i = 0;
	if (!(str || find))
		return (0);
	if (find[0] == '\0')
		return ((char *)(str));
	while (str[i] != '\0')
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (str[i + j] != '\0' && find[j] != '\0')
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
