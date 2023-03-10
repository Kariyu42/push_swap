/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/10 18:10:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	int		len;
	t_node	*stack_a;
	t_node	*stack_b;

	len = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	//len = node_size(stack_a);
	/*if (len <= 5)
		stack_a = sort_small_stack(stack_a);*/
	/*else
		stack_a = sort_big_stack();*/
	t_node *tmp = stack_a;
	while (stack_a)
	{
		printf("[%d]---> ", stack_a->num);
		stack_a = stack_a->next;
	}
	printf("NULL\n");
	do_sa(&tmp);
	while (tmp)
	{
		printf("[%d]---> ", tmp->num);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return (0);
}
