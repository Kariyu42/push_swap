/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/21 18:28:39 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	sort_big(t_list **stack_a, t_tools aid)
{
	t_list	*stack_b;
	t_list	*current;

	stack_b = NULL;
	current = *stack_a;
	aid.max = ft_lstsize(*stack_a) - 1;
	printf("aid.max = %d\n", aid.max);
	aid.max2 = ft_lstsize(*stack_a) - 2;
	printf("aid.max2 = %d\n", aid.max2);
	aid.max3 = ft_lstsize(*stack_a) - 3;
	printf("aid.max3 = %d\n", aid.max3);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != aid.max
			|| (*stack_a)->index != aid.max2
			|| (*stack_a)->index != aid.max3)
			do_push(stack_a, &stack_b, "pb\n");
		else
			do_rotate(stack_a, "ra\n");
	}
	print_list(stack_b, "stack_b"); // to be removed
	sort_three(stack_a);
	print_list(*stack_a, "stack_a"); // to be removed
	while (ft_lstsize(stack_b) != 0)
	{
		if (stack_b->index + 1 == (*stack_a)->index)
		{
			do_push(&stack_b, stack_a, "pa\n");
			print_list(*stack_a, "stack_a"); // to be removed
		}
		else
			do_rotate(&stack_b, "rb\n");
	}
	while ((*stack_a)->index != 0)
		do_rotate(stack_a, "ra\n");
}

void	sort_five(t_list **stack_a)
{
	int		i;
	t_list	*stack_b;

	i = 0;
	stack_b = NULL;
	while (i < 5)
	{
		if ((*stack_a)->index != 0 && (*stack_a)->index != 1)
			do_rotate(stack_a, "ra\n");
		else
			do_push(stack_a, &stack_b, "pb\n");
		i++;
	}
	sort_three(stack_a);
	if (stack_b->nbr < stack_b->next->nbr)
		do_swap(&stack_b, "sb\n");
	while (stack_b)
		do_push(&stack_b, stack_a, "pa\n");
}

void	sort_three(t_list **stack_a)
{
	int		max;

	max = find_biggest(*stack_a);
	if (max == (*stack_a)->nbr)
		do_rotate(stack_a, "ra\n");
	else if (max == (*stack_a)->next->nbr)
		do_revrotate(stack_a, "rra\n");
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		do_swap(stack_a, "sa\n");
}
