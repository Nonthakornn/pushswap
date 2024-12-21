/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:15 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 15:08:12 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

int	ft_lstsize(t_stack *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	double_free(char **str)
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

/*
//Remove this one will just use for debugging
void	display_stack(t_stack *list)
{
	t_stack	*ptr;

	ptr = list;
	while (ptr)
	{
		printf("index %d: %d\n", ptr->index, ptr->nbr);
		ptr = ptr->next;
	}
	printf("\n");
}
*/