/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:02:13 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/16 17:14:24 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->previous = NULL;
	new_node->nbr = nbr;
	new_node->cheapest = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_stack **head, t_stack *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	if (!head)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*last_node;

	if (!head || !new_node)
		return ;
	if (!(*head))
	{
		*head = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = ft_lstlast(*head);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
