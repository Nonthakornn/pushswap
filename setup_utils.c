/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:19:51 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 14:52:33 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->above_mid = 1;
		else
			stack->above_mid = 0;
		stack = stack->next;
		++i;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	set_before_push(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_min_top(t_stack **stack)
{
	t_stack	*smallest_node;

	smallest_node = find_smallest_node(*stack);
	while ((*stack)->nbr != smallest_node->nbr)
	{
		if (smallest_node->above_mid)
			ra(stack);
		else
			rra(stack);
	}
}

/*
void set_min_top(t_stack **stack)
{
	t_stack *smallest_node = find_smallest_node(*stack);

    while ((*stack)->nbr != smallest_node->nbr)
    {
        if (smallest_node->above_mid)
        {
            ra(stack);
        }
        else
        {
            rra(stack);
        }
    }
}
*/
