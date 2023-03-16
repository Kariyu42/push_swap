/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:36:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/16 17:05:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *stack;
	buf = tmp->next;
	tmp->next = buf->next;
	buf->next = tmp;
	*stack = buf;
}

void	do_push(t_list **stack1, t_list **stack2)
{
	t_list	*top;

	top = *stack1;
	*stack1 = *stack2;
	*stack2 = (*stack2)->next;
	top
}

void	do_rotate(t_list **head)
{
	t_list	*last;
	t_list	*first;

	first = *head;
	last = ft_lstlast(*head);
	last->next = first;
	*head = first->next;
	first->next = NULL;
}

void	do_revrotate(t_list **head)
{
	t_list	*last;
	t_list	*bef_last;

	last = *head;
	while (last->next)
	{
		bef_last = last;
		last = last->next;
	}
	bef_last->next = NULL;
	last->next = *head;
	*head = last;
}
