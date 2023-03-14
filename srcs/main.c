/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/13 18:51:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	int		len;
	t_list	*stack_a;
	//t_list	*stack_b;

	len = 0;
	stack_a = NULL;
	//stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	/*else if (len <= 5)
		sort_five(&stack_a);
	else
		stack_a = sort_big();*/

	/*-------------------------------------------------------------------*/

	t_list	*tmp = stack_a;
	while (stack_a)
	{
		printf("[%d]---> ", stack_a->nbr);
		stack_a = stack_a->next;
	}
	printf("NULL\n");
	stack_a = tmp;
	len = ft_lstsize(stack_a);
	if (len <= 3)
		sort_three(&stack_a);
	while (stack_a)
	{
		printf("[%d]---> ", stack_a->nbr);
		stack_a = stack_a->next;
	}
	printf("NULL\n");
	return (0);
}
