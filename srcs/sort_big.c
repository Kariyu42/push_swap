/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/25 19:17:50 by kquetat-         ###   ########.fr       */
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
			do_push(stack_a, &stack_b, "pb\n");
		else
			do_rotate(stack_a, "ra\n");
	}
	sort_three(stack_a);
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
	if (count > ft_lstsize(stack_a) / 2)
		count = ft_lstsize(stack_a) - count;
	stack_b->moves += count;
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		min_moves;

	current = *stack_b;
	min_moves = current->moves;
	while (current && current->moves != min_moves)
		current = current->next;
	while (stack_b && stack_b->ind)
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
				break ;
			else
				current = stack_b;
		}
	}
	// fonction qui remet stack_a avec le premier_element();
}
