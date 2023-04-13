/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:57:11 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 12:19:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	check_number_bonus(char *str)
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
