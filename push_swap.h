/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:26 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/06 22:07:16 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

//t_list
t_list *ft_lstnew(int data);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **head, t_list *new_node);
void	ft_lstadd_back(t_list **head, t_list *new_node);
void	free_list(t_list **head);

//utils
void	error_exit(void);
int		ft_lstsize(t_list *list);
void	double_free(char **str);
void	display_list(t_list *list); //Comment this out will use for debugging

//split
char **ft_split(char *str, char sep);

#endif