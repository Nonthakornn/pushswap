/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:57:37 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 14:59:09 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ptr;
	long	x;

	x = INT_MIN;
	ptr = stack;
	while (ptr)
	{
		if (ptr->nbr < x)
			return (0);
		x = ptr->nbr;
		ptr = ptr->next;
	}
	return (1);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;

	smallest_node = find_smallest_node(*stack_a);
	while ((*stack_a)->nbr != smallest_node->nbr)
	{
		if (smallest_node->above_mid)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

// void	sort_3(t_stack **stack_a)
// {
// 	int	num1;
// 	int	num2;
// 	int	num3;

// 	num1 = (*stack_a)->nbr;
// 	num2 = (*stack_a)->next->nbr;
// 	num3 = (*stack_a)->next->next->nbr;
// 	if (num1 > num2 && num1 < num3 && num2 < num3)
// 		sa(stack_a);
// 	else if (num1 > num2 && num1 > num3 && num2 < num3)
// 		ra(stack_a);
// 	else if (num1 < num2 && num1 > num3 && num2 > num3)
// 		rra(stack_a);
// 	else if (num1 < num2 && num1 < num3 && num2 > num3)
// 	{
// 		sa(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (num1 > num2 && num1 > num3 && num2 > num3)
// 	{
// 		sa(stack_a);
// 		rra(stack_a);
// 	}
// }

/*
num1 > num2 && num1 < num3 && num2 < num3
2 1 3 (sa)
num1 > num2 && num1 > num3 && num2 > num3
3 1 2 (ra)
num1 < num2 && num1 > num3 && num2 > num3
2 3 1 (rra)
num1 < num2 && num1 < num3 && num2 > num3
1 3 2 (sa) (ra)
num1 > num2 && num1 > num1 > num3 && num2 > num1
3 2 1 (sa) (rra)
*/
