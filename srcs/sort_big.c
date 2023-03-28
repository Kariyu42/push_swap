/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/27 15:02:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	count = 0;
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
	if ((*stack_a)->index > (*stack_b)->index)
		do_push(stack_b, stack_a, "pa\n");
	else
	{
		count = get_best_a(*stack_a, (*stack_b)->index);
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
	}
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
	while (current)
	{
		moves_count_b(stack_b, current);
		moves_count_a(stack_a, current);
		current = current->next;
		if (current == NULL)
		{
			push_to_a(stack_a, &stack_b);
			if (stack_b != NULL)
				current = stack_b;
			else
				break ;
		}
	}
	if ((*stack_a)->index != 0 && stack_b == NULL)
		final_sort(stack_a);
}
