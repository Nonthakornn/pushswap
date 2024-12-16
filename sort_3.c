/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:08:01 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/16 19:27:10 by nchencha         ###   ########.fr       */
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
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack_a)->nbr;
	num2 = (*stack_a)->next->nbr;
	num3 = (*stack_a)->next->next->nbr;
	if (num1 > num2 && num1 < num3 && num2 < num3)
		sa(stack_a);
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ra(stack_a);
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		rra(stack_a);
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

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
