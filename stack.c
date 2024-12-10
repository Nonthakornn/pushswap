/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:01:01 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/10 21:51:15 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_and_trim(char **argv)
{
	char	*join_str;
	char	*trim_arg;
	char	*temp;
	int		i;

	i = 1;
	join_str = ft_strdup("");
	while (argv[i])
	{
		trim_arg = ft_strtrim(argv[i], " ");
		if (!trim_arg || trim_arg[0] == '\0')
		{
			free(trim_arg);
			free(join_str);
			error_exit();
		}
		temp = ft_strjoin(join_str, trim_arg);
		free(trim_arg);
		free(join_str);
		join_str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (join_str);
}

void	init_stack(t_stack **stack, char **argv)
{
	t_stack	*new_node;
	char	*join_str;
	char	**split_str;
	int		i;

	join_str = join_and_trim(argv);
	split_str = ft_split(join_str, ' ');
	free(join_str);
	if (!parse(split_str))
		error_exit();
	i = 0;
	while (split_str[i])
	{
		new_node = ft_lstnew(ft_atoi(split_str[i]));
		if (!new_node)
		{
			double_free(split_str);
			error_exit();
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	double_free(split_str);
}

/*
	//Print split_str
	while (split_str[i]) 
	{
		printf("%s ", split_str[i]);
		i++;
	}
	printf("\n");
*/
