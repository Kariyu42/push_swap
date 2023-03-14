/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/14 18:45:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	find_biggest(t_list *stack)
{
	int	max;

	while (stack)
	{
		max = stack->nbr;
		while (stack && max <= stack->nbr)
			stack = stack->next;
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_list **stack_a)
{
	int		max;
	t_list	*last_elem;

	max = find_biggest(*stack_a);
	last_elem = ft_lstlast(*stack_a);
	if (max == (*stack_a)->nbr)
		do_ra(*stack_a);
	else if (max == (*stack_a)->next->nbr)
}