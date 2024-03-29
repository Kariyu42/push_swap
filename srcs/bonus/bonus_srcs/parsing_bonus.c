/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:48:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/15 16:38:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	free_split_bonus(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

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

static void	in_quotes(t_list **a_head, char *str)
{
	int			i;
	long long	num;
	char		**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	if (tmp[i] == NULL)
	{
		free_split_bonus(tmp);
		ft_error();
	}
	while (tmp[i] && check_number_bonus(tmp[i]))
	{
		num = arr_to_int(tmp[i]);
		ft_lstadd_back(a_head, ft_lstnew(num));
		i++;
	}
	free_split_bonus(tmp);
}

t_list	*parsing_bonus(int argc, char **argv)
{
	int		i;
	int		num;
	t_list	*a_head;

	i = 1;
	a_head = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			in_quotes(&a_head, argv[i]);
		else if (ft_isdigit(argv[i][0])
			|| ((argv[i][0] == '-' || argv[i][0] == '+')
			&& ft_isdigit(argv[i][1])))
		{
			check_number_bonus(argv[i]);
			num = arr_to_int(argv[i]);
			ft_lstadd_back(&a_head, ft_lstnew(num));
		}
		else
			ft_error();
		i++;
	}
	return (a_head);
}
