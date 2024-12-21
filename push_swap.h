/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/21 15:08:36 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	int				cheapest;
	int				above_mid;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

//t_stack
t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **head, t_stack *new_node);
void	free_stack(t_stack **head);

//utils
void	error_exit(void);
int		ft_lstsize(t_stack *list);
void	double_free(char **str);
// void	display_stack(t_stack *list);

//find_utils
t_stack	*find_biggest_node(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_smallest_node(t_stack *stack);

//stack
void	init_stack(t_stack **stack, char **argv);

//parse
int		parse(char **split_argv);

//split
char	**ft_split(char *str, char sep);

//sort3
int		is_sorted(t_stack *stack);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);

//sortn
void	sort_n(t_stack **stack_a, t_stack **stack_b);

//Operation
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);

// setup index
void	setup_stack_a(t_stack *stack_a, t_stack *stack_b);
void	setup_stack_b(t_stack *stack_a, t_stack *stack_b);

// setup Utils
void	set_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	set_before_push(t_stack **stack, t_stack *top_node, char name);
void	set_min_top(t_stack **stack);

#endif