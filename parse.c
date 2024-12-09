/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:47:32 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/09 23:52:04 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_valid_num(char *str)
{
	int 	i;
	long	num;

	if (!str)
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
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

static int check_dup(int num)
{

}

int parse(char **split_argv)
{
	int i = 0;
	while (split_argv[i])
	{
		if (!check_valid_num(split_argv[i]))
			error_exit();
		if (check_dup(ft_atoi(split_argv[i])))
			error_exit();
		i++;
	}
	return (1);

}