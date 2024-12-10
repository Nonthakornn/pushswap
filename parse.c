/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:47:32 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/10 21:54:25 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_valid_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	check_dup(int num, char **split_argv, int index)
{
	++index;
	while (split_argv[index])
	{
		if (num == ft_atoi(split_argv[index]))
			return (1);
		index++;
	}
	return (0);
}

int	parse(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i])
	{
		if (!check_valid_num(split_argv[i]))
		{
			double_free(split_argv);
			return (0);
		}
		if (check_dup(ft_atoi(split_argv[i]), split_argv, i))
		{
			double_free(split_argv);
			return (0);
		}
		i++;
	}
	return (1);
}
