/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:51:52 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 15:07:20 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_atb(t_stack **stack_a, t_stack **stack_b);
static void	move_bta(t_stack **stack_a, t_stack **stack_b);
void		rotate_ab(t_stack **st_a, t_stack **st_b, t_stack *cheapest);
void		rev_rotate_ab(t_stack **st_a, t_stack **st_b, t_stack *cheapest);

void	rotate_ab(t_stack **st_a, t_stack **st_b, t_stack *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target_node)
		rr(st_a, st_b);
	set_index(*st_a);
	set_index(*st_b);
}

void	rev_rotate_ab(t_stack **st_a, t_stack **st_b, t_stack *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target_node)
		rrr(st_a, st_b);
	set_index(*st_a);
	set_index(*st_b);
}

static void	move_atb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*stack_a);
	if (cheapest->above_mid && cheapest->target_node->above_mid)
		rotate_ab(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_mid) && (!(cheapest->target_node->above_mid)))
		rev_rotate_ab(stack_a, stack_b, cheapest);
	set_before_push(stack_a, cheapest, 'a');
	set_before_push(stack_b, cheapest->target_node, 'b');
	pb(stack_a, stack_b);
}

static void	move_bta(t_stack **stack_a, t_stack **stack_b)
{
	set_before_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_b, stack_a);
}

void	sort_n(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack_a;

	size_stack_a = ft_lstsize(*stack_a);
	if (size_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_stack_a-- > 3 && !is_sorted(*stack_a))
	{
		setup_stack_a(*stack_a, *stack_b);
		move_atb(stack_a, stack_b);
	}
	sort_3(stack_a);
	setup_stack_b(*stack_a, *stack_b);
	while (*stack_b)
	{
		setup_stack_b(*stack_a, *stack_b);
		move_bta(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_min_top(stack_a);
}

/*
Debugging
void	sort_n(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack_a;

	size_stack_a = ft_lstsize(*stack_a);
	if (size_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_stack_a-- > 3 && !is_sorted(*stack_a))
	{
		setup_stack_a(*stack_a, *stack_b);
		move_atb(stack_a, stack_b);
	}
	// printf("After Move 1: \n");
	// display_stack(*stack_a);
	// display_stack(*stack_b);
	sort_3(stack_a);
	setup_stack_b(*stack_a, *stack_b);
	printf("Setup:\n");
	display_stack(*stack_a);
	display_stack(*stack_b);

	while (*stack_b)
	{
		setup_stack_b(*stack_a, *stack_b);
		move_bta(stack_a, stack_b);
	}
	printf("After Move 2: \n");
	display_stack(*stack_a);
	display_stack(*stack_b);

	set_index(*stack_a);
	display_stack(*stack_a);
	set_min_top(stack_a);
}
*/