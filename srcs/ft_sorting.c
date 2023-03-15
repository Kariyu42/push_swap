/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/15 18:20:37 by kquetat-         ###   ########.fr       */
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
	
}

void	sort_three(t_list **stack_a)
{
	int		max;

	max = find_biggest(*stack_a);
	if (max == (*stack_a)->nbr)
	{
		do_ra(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (max == (*stack_a)->next->nbr)
	{
		do_rra(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
	{
		do_sa(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
}
