/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/18 15:49:03 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	sort_big(t_list **stack_a, int len)
{
	int		top;
	int		count;
	int		bottom;
	t_list *stack_b;

	count = 0;
	stack_b = NULL;
	
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
