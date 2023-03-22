/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/22 18:22:30 by kquetat-         ###   ########.fr       */
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
	aid.max2 = ft_lstsize(*stack_a) - 2;
	aid.max3 = ft_lstsize(*stack_a) - 3;
//	printf("max = %d\n", aid.max); // to be removed
//	printf("max2 = %d\n", aid.max2); // to be removed
//	printf("max3 = %d\n", aid.max3); // to be removed
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != aid.max
			&& (*stack_a)->index != aid.max2
			&& (*stack_a)->index != aid.max3)
			do_push(stack_a, &stack_b, "pb\n");
		else
			do_rotate(stack_a, "ra\n");
	}
	print_list(stack_b, "STACK_B"); // affiche list b apres push b
	print_index(stack_b); // affiche index de la liste b
	print_list(*stack_a, "STACK_A"); // list a apres push b
	sort_three(stack_a); // sort 3 de la liste a
	print_list(*stack_a, "STACK_A"); // affiche liste a apres sorting
	print_index(*stack_a); // affiche ses indexes
	printf("ft_lstsize = %d\n", ft_lstsize(stack_b));
	while (ft_lstsize(stack_b) != 0)
	{
		if ((*stack_a)->index - 1 == stack_b->index)
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
