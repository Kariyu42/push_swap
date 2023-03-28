/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/28 17:45:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	top_up_b(t_list **stack_a, t_list **stack_b, int max_index)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != max_index
			&& (*stack_a)->index != max_index - 1
			&& (*stack_a)->index != max_index - 2)
			do_push(stack_a, stack_b, "pb\n");
		else
			do_rotate(stack_a, "ra\n");
	}
	sort_three(stack_a);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		min_moves;

	min_moves = find_least_moves(*stack_b);
	count = get_least(*stack_b, min_moves);
	if (count > ft_lstsize(*stack_b) / 2)
	{
		count = ft_lstsize(*stack_b) - count;
		while (count-- > 0)
			do_revrotate(stack_b, "rrb\n");
	}
	else
		while (count-- > 0)
			do_rotate(stack_b, "rb\n");
//	if ((*stack_b)->index < (*stack_a)->index)
//		do_push(stack_b, stack_a, "pa\n");
//	else
//	{
		count = get_best_a(*stack_a, (*stack_b)->index);
		printf("count best A = %d\n", count);
		if (count > ft_lstsize(*stack_a) / 2)
		{
			count = ft_lstsize(*stack_a) - count;
			while (count-- > 0)
				do_revrotate(stack_a, "rra\n");
		}
		else
			while (count-- > 0)
				do_rotate(stack_a, "ra\n");
		do_push(stack_b, stack_a, "pa\n");
//	}
}

int	find_first(t_list *stack_a)
{
	int	count;
	t_list *current;

	count = 0;
	current = stack_a;
	while (current)
	{
		if (current->index == 0)
			break ;
		count++;
		current = current->next;
	}
	return (count);
}

void	final_sort(t_list **stack_a)
{
	int	count;

	count = find_first(*stack_a);
	if (count > ft_lstsize(*stack_a) / 2)
	{
		count = ft_lstsize(*stack_a) - count;
		while (count-- > 0)
			do_revrotate(stack_a, "rra\n");
	}
	else
		while (count-- > 0)
			do_rotate(stack_a, "ra\n");
}

void	sort_big(t_list **stack_a, t_tools aid)
{
	t_list	*stack_b;
	t_list	*current;

	stack_b = NULL;
	aid.max = ft_lstsize(*stack_a) - 1;
	top_up_b(stack_a, &stack_b, aid.max);
	current = stack_b;
	init_moves(stack_b);
	while (current)
	{
		moves_count_b(stack_b, current);
		moves_count_a(stack_a, current);
		current = current->next;
		if (current == NULL)
		{
			printf("\033[1;32m-------------------------FIN DE PARCOURS-------------------------------\033[0m\n");
			printf("\033[1;31mSTACK A INDEX\033[0m\n");
			print_index(*stack_a); // index stack_A
			printf("\033[1;33mSTACK B INDEX\033[0m\n");
			print_index(stack_b); // index stack_B
//			print_moves(stack_b, "moves for stack_B"); // to be removed
			push_to_a(stack_a, &stack_b);
			printf("\033[1;31mstack A\033[0m \033[1;34mAfter push_a function();\033[0m\n");
			print_index(*stack_a); // index stack_a
			printf("\033[1;33mstack B\033[0m \033[1;34mAfter push_a function();\033[0m\n");
			print_index(stack_b);
			if (stack_b != NULL)
			{
				init_moves(stack_b);
				current = stack_b;
			}
			else
				break ;
		}
	}
	if ((*stack_a)->index != 0)
		final_sort(stack_a);
}
