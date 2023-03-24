/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/23 21:55:16 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	top_up_b(t_list **stack_a, t_list **stack_b, int max_index)
{
	t_list	*stack_b;

	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != max_index
			&& (*stack_a)->index != max_index - 1
			&& (*stack_a)->index != max_index - 2)
			do_push(stack_a, &stack_b, "pb\n");
		else
			do_rotate(stack_a, "ra\n");
	}
	sort_three(stack_a);
}

void	sort_big(t_list **stack_a, t_tools aid)
{
	t_list	*stack_b;

	stack_b = NULL;
	aid.max = ft_lstsize(*stack_a) - 1;
	top_up_b(stack_a, &stack_b, aid.max);
	while (stack_b)
	{
		
	}
}
