/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/06 23:27:09 by nchencha         ###   ########.fr       */
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
void	display_stack(t_stack *list); //Comment this out will use for debugging

//split
char **ft_split(char *str, char sep);

#endif