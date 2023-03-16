/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/16 15:30:48 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include <stdio.h>

void	print_list(t_list *list)
{
	printf("*** my list ***\n");
	while (list)
	{
		printf("[%d]--> ", list->nbr);
		list = list->next;
	}
	printf("NULL\n");
}

void	print_index(t_list *list)
{
	while (list)
	{
		printf("[%d]--> ", list->index);
		list = list->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	len = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	simplified_stack(&stack_a);
//	print_index(stack_a); //to be removed
	/*-------------------------------------------------------------------*/
	print_list(stack_a); // to be removed
	len = ft_lstsize(stack_a);
	do_push(&stack_a, &stack_b);
//	if (len <= 3)
//		sort_three(&stack_a);
//	else if (len > 3 && len <= 5)
//		sort_five(&stack_a);
//	else
//		sort_big(&stack_a);
	print_list(stack_a); // to be removed
	print_list(stack_b); // to be removed
	return (0);
}
