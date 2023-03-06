/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:54:26 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/06 15:41:00 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*last_node(t_node *ptr)
{
	while (ptr)
	{
		if (ptr->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

int	node_size(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	add_node_back(t_node **ptr, t_node *new_node)
{
	t_node	*tmp;

	if (!(*ptr))
	{
		*ptr = new_node;
		return ;
	}
	tmp = last_node(*ptr);
	tmp->next = new_node;
}

t_node	*new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->num = data;
	new_node->next = NULL;
	return (new_node);
}
