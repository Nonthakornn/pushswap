/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:56:15 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/06 22:06:37 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == sep)
			in_word = 0;
		else if (*str != sep && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

static char	*fill_word(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	free_ft_split(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
	free(str);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		start;
	int		end;
	char	**arr;

	start = 0;
	end = 0;
	i = 0;
	arr = malloc(sizeof(char *) * (word_count(str, sep) + 1));
	if (!arr)
		return (NULL);
	while (i < word_count(str, sep))
	{
		while (str[end] == sep)
			end++;
		start = end;
		while (str[end] != sep && str[end])
			end++;
		arr[i] = fill_word(str, start, end);
		if (!arr[i])
			free_ft_split(arr);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
