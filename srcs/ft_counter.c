/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:09:15 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/29 16:51:57 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_least_moves(t_list *stack_b)
{
	t_list	*current;
	int		min_moves;

	current = stack_b;
	min_moves = stack_b->total;
	while (current)
	{
		if (current->total < min_moves)
			min_moves = current->total;
		current = current->next;
	}
	return (min_moves);
}

int	get_least(t_list *stack, int min_moves)
{
	int		count;
	t_list *current;

	count = 0;
	current = stack;
	while (current && current->total != min_moves)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	get_best_a(t_list *stack_a, int b_index)
{
	int		count;
	t_list *current;

	count = 0;
	current = stack_a;
	while (current)
	{
		if (current->index > b_index)
			break ;
		count++;
		current = current->next;
	}
	return (count);
}

void	moves_count_b(t_list *stack_b, t_list *current)
{
	t_list	*lst;

	lst = stack_b;
	if (stack_b->index == current->index)
		current->moves_b = 0;
	else
	{
		while (lst && lst->index != current->index)
		{
			current->moves_b += 1;
			lst = lst->next;
		}
		if (current->moves_b > ft_lstsize(stack_b) / 2)
			current->moves_b = ft_lstsize(stack_b) - current->moves_b;
	}
}

void	moves_count_a(t_list **stack_a, t_list *stack_b)
{
	int		big_win;
	t_list	*current;

	current = *stack_a;
	big_win = best_index(current, stack_b);
	while (current && current->index != big_win)
	{
		stack_b->moves_a += 1;
		current = current->next;
	}
	stack_b->total = stack_b->moves_a + stack_b->moves_b;
}
