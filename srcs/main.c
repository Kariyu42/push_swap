/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/22 14:12:10 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include <stdio.h>

void	print_list(t_list *list, char *str)
{
	t_list	*current;

	current = list;
	printf("--------- %s ---------\n\n", str);
	while (current)
	{
		printf("[%d]--> ", current->nbr);
		current = current->next;
	}
	printf("NULL\n\n");
}

void	print_index(t_list *list)
{
	t_list	*current;

	current = list;
	printf("----------------- INDEX ------------------\n");
	while (current)
	{
		printf("[%d]--> ", current->index);
		current = current->next;
	}
	printf("NULL\n");
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	int		len;
	t_tools	aid;
	t_list	*stack_a;

	len = 0;
	aid.max = 0;
	aid.max2 = 0;
	aid.max3 = 0;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	simplified_stack(&stack_a);
	/*-------------------------------------------------------------------*/
//	print_list(stack_a, "STACK_A *COLLECTED*"); // to be removed
//	print_index(stack_a); // to be removed
	len = ft_lstsize(stack_a);
	if (len <= 3)
		sort_three(&stack_a);
	else if (len > 3 && len <= 5)
		sort_five(&stack_a);
	else
		sort_big(&stack_a, aid);
	//print_list(stack_a, "stack_a"); // to be removed
	return (0);
}
