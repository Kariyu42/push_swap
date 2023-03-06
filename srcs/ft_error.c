/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:46:29 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/06 14:30:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	check_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			count++;
			i++;
		}
		if (count == 2)
			ft_error();
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_error();
	}
	return (1);
}

void	check_duplicates(t_node *stack_a)
{
	int		nbr;
	t_node	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a;
		nbr = tmp->num;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (nbr == tmp->num)
				ft_error();
		}
		stack_a = stack_a->next;
	}
}

void	check_order(t_node *stack_a)
{
	int		nbr;
	t_node	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a;
		nbr = tmp->num;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (nbr > tmp->num)
				return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "The stack is already sorted!\n", 29);
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
