/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:18:16 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/17 13:26:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_biggest(t_list *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	find_smallest(t_list *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (min > stack->nbr)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

void	simplified_stack(t_list **head)
{
	int		nbr;
	int		count;
	t_list	*tmp;
	t_list	*current;

	current = *head;
	while (current)
	{
		nbr = current->nbr;
		tmp = *head;
		count = 0;
		while (tmp)
		{
			if (nbr > tmp->nbr)
				count++;
			tmp = tmp->next;
		}
		current->index = count;
		current = current->next;
	}
}
