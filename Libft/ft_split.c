/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhannsil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:19:06 by jhannsil          #+#    #+#             */
/*   Updated: 2026/06/12 13:19:08 by jhannsil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static int	len_words_array(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static int	create_words(char **arr, const char *str, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			len = len_words_array(str + i, c);
			arr[j] = ft_substr(str, i, len);
			if (arr[j] == NULL)
			{
				free_mem(arr, j);
				return (0);
			}
			i = i + len;
			j++;
		}
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (!create_words(array, s, c))
		return (NULL);
	return (array);
}
