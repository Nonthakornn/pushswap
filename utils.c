/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:15 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/13 14:28:29 by nchencha         ###   ########.fr       */
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

void double_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_stack	*find_biggest_node(t_stack *stack)
{
	long	max;
	t_stack	*biggest_node;

	if (!stack)
		return NULL;
	max = INT_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

//Remove this one will just use for debugging
void	display_stack(t_stack *list)
{
	t_stack	*ptr;

	ptr = list;
	while (ptr)
	{
		printf("%d ", ptr->nbr);
		ptr = ptr->next;
	}
	printf("\n");
}
