/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/13 18:47:43 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	find_max(t_list *stack)
{
	int	max;

	while (stack)
	{
		max = stack->nbr;
		while (max >= stack->nbr && stack)
			stack = stack->next;
		if (stack == NULL)
			break ;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_list **stack_a)
{
	int	max;

	max = find_max(*stack_a);
	if (max == (*stack_a)->nbr)
	{
		do_ra(stack_a);
		write(1, "sa\n", 3);
	}
	else if (max == (*stack_a)->next->nbr)
	{
		do_sa(stack_a);
		write(1, "sa\n", 3);
	}
	if (max == (*stack_a)->nbr)
	{
		do_ra(stack_a);
		write(1, "ra\n", 3);
	}
}