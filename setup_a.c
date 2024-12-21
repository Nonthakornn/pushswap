/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:16:56 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 14:37:32 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack *stack_a, t_stack *stack_b);
static void	cost_of_a(t_stack *stack_a, t_stack *stack_b);

void	setup_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_of_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	long	match_index;
	t_stack	*target_node;
	t_stack	*current;

	while (stack_a)
	{
		match_index = INT_MIN;
		current = stack_b;
		while (current)
		{
			if (current->nbr < stack_a->nbr && current->nbr > match_index)
			{
				match_index = current->nbr;
				target_node = current;
			}
			current = current->next;
		}
		if (match_index == INT_MIN)
			stack_a->target_node = find_biggest_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_of_a(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_mid))
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->target_node->above_mid)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += size_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}
