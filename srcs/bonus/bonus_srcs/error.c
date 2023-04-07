/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:57:11 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/07 17:57:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '-' && str[i + 1] == '0')
		ft_error();
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

void	check_duplicates(t_list *stack_a)
{
	int		nbr;
	t_list	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a;
		nbr = tmp->nbr;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (nbr == tmp->nbr)
				ft_error();
		}
		stack_a = stack_a->next;
	}
}

void	check_order(t_list *stack_a)
{
	int		nbr;
	t_list	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a;
		nbr = tmp->nbr;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (nbr > tmp->nbr)
				return ;
		}
		stack_a = stack_a->next;
	}
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
