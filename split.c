/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:09:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 15:25:22 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *str, char sep);
static char	*fill_word(char *str, int start, int end);
static void	free_ft_split(char **str);
static char	**hadle_allocate_fail(char **arr);

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
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**hadle_allocate_fail(char **arr)
{
	free_ft_split(arr);
	return (NULL);
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
			return (hadle_allocate_fail(arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	char **result = ft_split(av[1], ' ');
// 	while (result[i])
// 	{
// 		printf("%s ", result[i]);
// 		i++;
// 	}
// 	free_ft_split(result);
// }