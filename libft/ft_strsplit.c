/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 04:37:25 by llopez            #+#    #+#             */
/*   Updated: 2017/11/16 13:05:57 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count_words;
	int	i;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count_words);
}

static char	**ft_str_load(char const *s, char c, char **tmp)
{
	int i;
	int word_index;
	int count_letters;

	word_index = 0;
	i = 0;
	while (s[i])
	{
		count_letters = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tmp[word_index][count_letters] = s[i];
			count_letters++;
			i++;
		}
		word_index++;
	}
	return (tmp);
}

static char	**ft_alloc(char const *s, char c, char **tmp)
{
	int i;
	int word_index;
	int count_letters;

	count_letters = 0;
	word_index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			count_letters++;
		}
		if (count_letters > 0)
		{
			tmp[word_index] = ft_strnew(count_letters);
			count_letters = 0;
			word_index++;
		}
	}
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * (count_words + 1))))
		return (NULL);
	tmp[count_words] = NULL;
	tmp = ft_alloc(s, c, tmp);
	tmp = ft_str_load(s, c, tmp);
	return (tmp);
}
