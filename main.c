/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:40 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/07 00:07:08 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, char **argv)
{
	t_stack	*new_node;
	char	*join_str;
	char	*temp;
	char	**split_str;
	int		i;

	i = 1;
	join_str = ft_strdup("");
	while (argv[i])
	{
		temp = ft_strjoin(join_str, argv[i]);
		free(join_str);
		join_str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	split_str = ft_split(join_str, ' ');
	free(join_str);
	i = 0;
	while(split_str[i] && split_str)
	{
		new_node = ft_lstnew(ft_atoi(split_str[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	//double_free(split_str);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (0);
	init_stack(&stack_a, argv);
	display_stack(stack_a);
	free_stack(&stack_a);
}

/*
Checking my linklist
int main()
{
	t_stack *head;
	t_stack *node1;
	t_stack *node2;
	
	head = ft_lstnew(10);
	node1 = ft_lstnew(20);
	node2 = ft_lstnew(30);

	printf("Default: ");
	display_stack(head);

	printf("Add front: ");
	ft_lstadd_front(&head,node1);
	display_stack(head);

	printf("Size: %d\n", ft_lstsize(head));

	t_stack *last_node = ft_lstlast(head);
	printf("Last Node: %d\n", last_node->nbr);

	ft_lstadd_back(&head,node2);
	display_stack(head);
	free_stack(&head);
}
*/

/*
Parsing:
Invalid
Not int -> Error\n
    “1 3 4 one”
    “1 3 4 + 7”
    “1 1.0 9”

Overflow/Underflow -> Error\n
>2147483647
<-2147483648

Empty arguments -> Error
    “” 1
    "  " 1 2 3
    "      "
Duplicates
    “1 2 3 4 1”

Valid arg
./push_swap “ 1 2 3 4”
./push_swap 1 2 3 4
Could be all numbers in one arg or several args
./push_swap “1 2 3 4”“   6 14 412 “
So each arg contains several numbers

ok_input
1 -> return 0
4 +2 5 1
"4" +2 5 "1"
"  4  " " +2 " "5    1"
42 "1 7" 9 "  25   10 "
00000 +0002 -2222 "+0000009     -000009"
2147483647 "-2147483648 00000000000000000000000001 +002 -002"

Not sure error check with checker
//./push_swap -> exit (0)
./push_swap 1 1 2 -> exit(255)
*/ 
