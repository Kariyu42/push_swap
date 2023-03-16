/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/16 14:49:37 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	find_biggest(t_list *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

void	sort_five(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*current;
	int		max;
	t_list	*stack_b;

	max = find_biggest(*stack_a);
	stack_b = NULL;
	current = *stack_a;
	while (current)
	{
		if (max == current->nbr)
			do_push();
		current = current->next;
	}
}

void	sort_three(t_list **stack_a)
{
	int		max;

	max = find_biggest(*stack_a);
	if (max == (*stack_a)->nbr)
	{
		do_rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (max == (*stack_a)->next->nbr)
	{
		do_revrotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
	{
		do_swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
}
