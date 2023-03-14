/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:36:40 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/12 12:14:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_sa(t_list **stack)
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *stack;
	buf = tmp->next;
	tmp->next = buf->next;
	buf->next = tmp;
	*stack = buf;
}

void	do_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
}

void	do_ra(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	*head = ft_lstlast(*head);
	(*head)->next = tmp;
	*head = tmp->next;
}

void	do_rra(t_list **head)
{
	int		len;
	t_list	*tmp;
	t_list	*buf;

	tmp = *head;
	buf = *head;
	len = ft_lstsize(*head);
	tmp = ft_lstlast(tmp);
	*head = tmp;
	(*head)->next = buf;
	while (len - 1 > 1)
	{
		*head = (*head)->next;
		len--;
	}
	(*head)->next = NULL;
}

void	do_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
}
