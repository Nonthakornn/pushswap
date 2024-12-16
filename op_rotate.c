/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:13:27 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/16 16:47:47 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	first_node = *head;
	last_node = ft_lstlast(*head);
	*head = first_node->next;
	(*head)->previous = NULL;
	last_node->next = first_node;
	first_node->previous = last_node;
	first_node->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
