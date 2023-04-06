/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/05 12:53:24 by kquetat-         ###   ########.fr       */
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
			{
				do_push(stack_a, stack_b, "pb\n");
				if ((*stack_b)->index > max_index / 2
					&& ft_lstsize(*stack_b) != 1)
					do_rotate(stack_b, 'b');
			}
		else
			do_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
}

int	find_sup_index(int best_index, t_list *stack_a)
{
	t_list	*current;
	int		sup_index;

	sup_index = best_index + 1;
	current = stack_a;
	while (current && sup_index != current->index)
	{
		current = current->next;
		if (!current)
		{
			sup_index++;
			current = stack_a;
		}
	}
	return (sup_index);
}

int	locate_index(t_list **stack, int index)
{
	int		count;
	t_list	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	return (count);
}

int	get_rotate_dir(t_list *stack, int loc)
{
	int	middle;
	int	size;
	int	direction;

	direction = 0;
	size = ft_lstsize(stack);
	middle = size / 2;
	if (loc >= middle)
		direction = 1;
	return (direction);
}

void	sync_rotate_top(t_list **a, t_list **b, int index, int sup_index)
{
	int	loc_a;
	int	loc_b;

	loc_a = locate_index(a, sup_index);
	loc_b = locate_index(b, index);
	while (*a && (*a)->index != sup_index
		&& *b && (*b)->index != index)
	{
		if (get_rotate_dir(*a, loc_a) == 0 && get_rotate_dir(*b, loc_b) == 0)
			do_rr(a, b, "rr\n");
		else if (get_rotate_dir(*a, loc_a) == 1 && get_rotate_dir(*b, loc_b) == 1)
			do_rrr(a, b, "rrr\n");
		else
			break ;
	}
}

void	get_index_top(t_list **stack, int index, char c)
{
	int	loc;

	loc = locate_index(stack, index);
	while (*stack && (*stack)->index != index)
	{
		if (get_rotate_dir(*stack, loc) == 0)
			do_rotate(stack, c);
		else if (get_rotate_dir(*stack, loc) == 1)
			do_revrotate(stack, c);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	sup_index;
	int	best_index;

	best_index = find_least_moves(*stack_b);
	sup_index = find_sup_index(best_index, *stack_a);
	sync_rotate_top(stack_a, stack_b, best_index, sup_index);
	get_index_top(stack_a, sup_index, 'a');
	get_index_top(stack_b, best_index, 'b');
	do_push(stack_b, stack_a, "pa\n");
}

int	find_first(t_list *stack_a)
{
	int		count;
	t_list	*current;

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

void	final_sort(t_list **stack_a, int index)
{
	int	loc;

	loc = locate_index(stack_a, index);
	while ((*stack_a)->index != index)
	{
		if (get_rotate_dir(*stack_a, loc) == 0)
			do_rotate(stack_a, 'a');
		else if (get_rotate_dir(*stack_a, loc) == 1)
			do_revrotate(stack_a, 'a');
	}
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
			push_to_a(stack_a, &stack_b);
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
		final_sort(stack_a, 0);
}
