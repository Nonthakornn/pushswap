/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:46:20 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 14:40:49 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *stack_a, t_stack *stack_b);

void	setup_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b(stack_a, stack_b);
}

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	long	match_index;
	t_stack	*current;
	t_stack	*target_node;

	while (stack_b)
	{
		match_index = INT_MAX;
		current = stack_a;
		while (current)
		{
			if (current->nbr > stack_b->nbr && current->nbr < match_index)
			{
				match_index = current->nbr;
				target_node = current;
			}
			current = current->next;
		}
		if (match_index == INT_MAX)
			stack_b->target_node = find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}
