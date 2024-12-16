/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:14:51 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/16 19:25:08 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = ft_lstlast(*head);
	before_last_node = last_node->previous;
	before_last_node->next = NULL;
	last_node->previous = NULL;
	last_node->next = *head;
	(*head)->previous = last_node;
	*head = last_node;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
