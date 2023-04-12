/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:54:39 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/11 14:27:32 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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
		else if (get_rotate_dir(*a, loc_a) == 1
			&& get_rotate_dir(*b, loc_b) == 1)
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
