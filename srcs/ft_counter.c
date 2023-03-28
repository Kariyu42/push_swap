/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:09:15 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/27 14:42:16 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_least_moves(t_list *stack_b)
{
	t_list	*current;
	int		min_moves;

	current = stack_b;
	min_moves = stack_b->moves;
	while (current)
	{
		if (current->moves < min_moves)
			min_moves = current->moves;
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
	while (current && current->moves != min_moves)
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
		if (current->index < b_index)
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
		current->moves = 0;
	else
	{
		while (lst && lst->index != current->index)
		{
			current->moves += 1;
			lst = lst->next;
		}
		if (current->moves > ft_lstsize(stack_b) / 2)
			current->moves = ft_lstsize(stack_b) - current->moves;
	}
}

void	moves_count_a(t_list **stack_a, t_list *stack_b)
{
	t_list	*lst;
	int		count;

	count = 0;
	lst = *stack_a;
	if (lst && lst->index > stack_b->index)
		return ;
	while (lst && lst->index < stack_b->index)
	{
		count++;
		lst = lst->next;
	}
	if (count > ft_lstsize(*stack_a) / 2)
		count = ft_lstsize(*stack_a) - count;
	stack_b->moves += count;
}
