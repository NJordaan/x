/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:37:43 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/16 14:02:17 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_number_of_words(char const *s, char c)
{
	int i;
	int n;

	if (s[0] != c)
		n = 1;
	else
		n = 0;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static	int		get_word_len(char const *s, int i, char c)
{
	int	n;

	n = 0;
	while (s[i++] != c)
		n++;
	return (n);
}

static	char	*get_word(char const *s, int i, char c)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * get_word_len(s, i, c) + 1);
	if (!word)
		return (0);
	j = 0;
	while (s[i] != c && s[i])
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	k = get_number_of_words(s, c);
	if (!(words = (char **)ft_memalloc(sizeof(char *) * (k + 1))))
		return (0);
	i = 0;
	j = 0;
	if (s[0] != c && s[0] != '\0')
		words[j++] = get_word(s, i, c);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			words[j++] = get_word(s, i, c);
		i++;
	}
	words[j] = 0;
	return (words);
}
