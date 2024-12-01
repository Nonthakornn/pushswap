/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:14:40 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/01 22:20:40 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit (0);
}

/*
Checking my linklist
int main()
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	
	head = ft_lstnew(10);
	node1 = ft_lstnew(20);
	node2 = ft_lstnew(30);

	printf("Default: ");
	display_list(head);

	printf("Add front: ");
	ft_lstadd_front(&head,node1);
	display_list(head);

	printf("Size: %d\n", ft_lstsize(head));

	t_list *last_node = ft_lstlast(head);
	printf("Last Node: %d\n", last_node->data);

	ft_lstadd_back(&head,node2);
	display_list(head);
	free_list(&head);
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