/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/19 15:45:28 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*push_node;

	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_node->previous = NULL;
	if (!(*dst))
	{
		(*dst) = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = (*dst);
		push_node->next->previous = push_node;
		(*dst) = push_node;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}
