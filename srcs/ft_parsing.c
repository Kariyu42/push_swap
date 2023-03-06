/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:50:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/06 11:28:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <limits.h>

static long	arr_to_int(char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\f' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
		if ((num > INT_MAX && sign == 1) || num > 2147483648)
			ft_error();
	}
	return (sign * num);
}

static void	in_quotes(t_node **a_head, char *str)
{
	int			i;
	long long	num;
	char		**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	if (tmp[i] == NULL)
		ft_error();
	while (tmp[i] && check_number(tmp[i]))
	{
		
		num = arr_to_int(tmp[i]);
		add_node_back(a_head, new_node(num));
		i++;
	}
}

t_node	*parsing_argv(int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*a_head;

	i = 1;
	a_head = NULL;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ')) //multiple number argv[i]
			in_quotes(&a_head, argv[i]);
		else if (ft_isdigit(argv[i][0]) || ((argv[i][0] == '-' || argv[i][0] == '+')
			&& ft_isdigit(argv[i][1]))) //single number with + or - included
		{
			check_number(argv[i]);
			num = arr_to_int(argv[i]);
			add_node_back(&a_head, new_node(num));
		}
		else
			ft_error();
		i++;
	}
	return (a_head);
}
