/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/16 16:44:57 by nchencha         ###   ########.fr       */
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
	int				above_mid;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;


//t_stack
t_stack *ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_front(t_stack **head, t_stack *new_node);
void	ft_lstadd_back(t_stack **head, t_stack *new_node);
void	free_stack(t_stack **head);

//utils
void	error_exit(void);
int		ft_lstsize(t_stack *list);
void	double_free(char **str);
t_stack	*find_biggest_node(t_stack *stack);
void	display_stack(t_stack *list); //Comment this out will use for debugging

//stack
void	init_stack(t_stack **stack, char **argv);

//parse
int		parse(char **split_argv);

//split
char	**ft_split(char *str, char sep);

//sort
int		is_sorted(t_stack *stack);
void	sort_3(t_stack **stack_a);

//Operation
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a ,t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif