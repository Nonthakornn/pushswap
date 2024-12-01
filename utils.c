/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:15 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/01 22:15:25 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

int	ft_lstsize(t_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

//Remove this one will just use for debugging
void	display_list(t_list *list)
{
	t_list	*ptr;

	ptr = list;
	while (ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
