/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:50:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/01 17:47:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	}
	printf("num = %ld\n", num);
	if (num > 2147483647 || num < -2147483648)
		ft_error();
	return (sign * num);
}

static t_node	*in_quotes(char *str)
{
	int			i;
	long long	num;
	t_node		*ptr;
	char		**tmp;

	i = 0;
	ptr = NULL;
	tmp = ft_split(str, ' ');
	while (tmp[i])
	{
		num = arr_to_int(tmp[i]);
		add_node_back(&ptr, new_node(num));
		i++;
	}
	return (ptr);
}

t_node	*parsing_argv(int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*a_head;

	i = 1;
	a_head = NULL;
	while (argv[i] && i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			a_head = in_quotes(argv[i]);
		else
		{
			num = arr_to_int(argv[i]);
			add_node_back(&a_head, new_node(num));
		}
		i++;
	}
	return (a_head);
}