/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:57:11 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/15 16:38:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	check_number_bonus(char *str)
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

void	dup_bonus(t_list *stack_a)
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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
