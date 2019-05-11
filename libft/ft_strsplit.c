/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:45:38 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/09 10:45:39 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words_strsplit(char *str, char c)
{
	int i;
	int word;
	int check;

	i = 0;
	word = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			check = 0;
		else if (!check)
		{
			check = 1;
			word++;
		}
		i++;
	}
	return (word);
}

static int		ft_word_size_strsplit(char *str, char c)
{
	int i;

	i = 0;
	while ((str[i] != c) && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_alloc_strsplit(char **tab, int count, char *s, char c)
{
	int i;
	int j;
	int word;

	i = -1;
	j = 0;
	word = 0;
	while (++i <= count - 1)
	{
		while (s[j] == c)
			j++;
		word = ft_word_size_strsplit((char *)s + j, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (word + 1))))
			return (0);
		ft_strncpy(tab[i], (char *)s + j, word);
		tab[i][word] = 0;
		j += word;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;

	i = 0;
	if (s && c)
	{
		count = ft_count_words_strsplit((char *)s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
			return (NULL);
		i = ft_alloc_strsplit(tab, count, (char *)s, c);
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
