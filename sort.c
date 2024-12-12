/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:28:46 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/12 22:29:39 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ptr;
	int		x;

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