/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/02 23:19:18 by kquetat-         ###   ########.fr       */
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
			do_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
}

/*void	push_worthy(t_list **stack_a, t_list **stack_b, int count)
{
	if (count > ft_lstsize(*stack_b) / 2)
		while (count-- > 0)
			do_revrotate(stack_b, "rrb\n");
	else if (count < ft_lstsize(*stack_b) / 2)
		while (count-- > 0)
			do_rotate(stack_b, "rb\n");
	if ((*stack_b)->moves_a > ft_lstsize(*stack_a) / 2)
	{
		(*stack_b)->moves_a = ft_lstsize(*stack_a) - (*stack_b)->moves_a;
		while ((*stack_b)->moves_a-- > 0)
			do_revrotate(stack_a, "rra\n");
	}
	else
		while ((*stack_b)->moves_a-- > 0)
			do_rotate(stack_a, "ra\n");
	do_push(stack_b, stack_a, "pa\n");
}*/

int	find_sup_index(int best_index, t_list *stack_a)
{
	t_list	*current;
	int		sup_index;

	current = stack_a;
	sup_index = best_index + 1;
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
	while (current && current->index != index)
	{
		count++;
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
	if (loc < middle)
		direction = 1;
	else if (loc > middle || (loc == middle && size % 2 == 0))
		direction = 2;
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
		if (loc_a > ft_lstsize(*a) / 2 && loc_b > ft_lstsize(*b) / 2)
			do_rrr(a, b, "rr\n");
		else if (loc_a <= ft_lstsize(*a) / 2 && loc_b <= ft_lstsize(*b) / 2)
			do_rr(a, b, "rrr\n");
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
		if (get_rotate_dir(*stack, loc) == 1)
			do_rotate(stack, c);
		else if (get_rotate_dir(*stack, loc) == 2)
			do_revrotate(stack, c);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		sup_index;
	int		best_index;

	best_index = find_least_moves(*stack_b);
//	printf("best_index = %d\n", best_index);
	sup_index = find_sup_index(best_index, *stack_a);
//	printf("sup_index = %d\n", sup_index);
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

void	final_sort(t_list **stack_a)
{
	int	count;

	count = find_first(*stack_a);
	if (count > ft_lstsize(*stack_a) / 2)
	{
		count = ft_lstsize(*stack_a) - count;
		while (count-- > 0)
			do_revrotate(stack_a, 'a');
	}
	else
		while (count-- > 0)
			do_rotate(stack_a, 'a');
}

void	sort_big(t_list **stack_a, t_tools aid)
{
//	int	i = 0;
	t_list	*stack_b;
	t_list	*current;

	stack_b = NULL;
	aid.max = ft_lstsize(*stack_a) - 1;
	top_up_b(stack_a, &stack_b, aid.max);
	current = stack_b;
	init_moves(stack_b);
	while (current)
	{
		moves_count_b(stack_b, current); // nombre de coup pour remettre au sommet de B.
		moves_count_a(stack_a, current); // nombre de coup rajouter pour bien placer les elements dans A.
		current = current->next;
		if (current == NULL)
		{
//			i++;
//			printf("\033[1;32m-------------------------FIN DE PARCOURS-------------------------------\033[0m\n");
//			printf("\033[1;32m%de passage\033[0m\n", i);
//			printf("\033[1;31mSTACK A INDEX\033[0m\n");
//			print_index(*stack_a); // index stack_A
//			printf("\033[1;33mSTACK B INDEX\033[0m\n");
//			print_index(stack_b); // index stack_B
//			print_moves(stack_b, "moves for stack_B"); // to be removed
			push_to_a(stack_a, &stack_b);
//			printf("\033[1;31mstack A\033[0m \033[1;34mAfter push_a function();\033[0m\n");
//			print_index(*stack_a); // index stack_a
//			printf("\033[1;33mstack B\033[0m \033[1;34mAfter push_a function();\033[0m\n");
//			print_index(stack_b);
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
