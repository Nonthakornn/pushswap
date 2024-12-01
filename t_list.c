/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:02:13 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/01 22:19:40 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **head, t_list *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*ptr;

	ptr = head;
	if (!head)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back(t_list **head, t_list *new_node)
{
	if (!head || !new_node)
		return ;
	if (!(*head))
	{
		*head = new_node;
		return ;
	}
	else
		ft_lstlast(*head)->next = new_node;
}

void	free_list(t_list **head)
{
	t_list	*tmp;

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
