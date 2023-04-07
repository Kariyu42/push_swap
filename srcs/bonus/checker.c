/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:34 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/07 18:09:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_input(char *str)
{
	
}

int	main(int argc, char **argv)
{
	int		read;
	char	*str;
	t_list	*stack_a;

	read = 1;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	while (read != 0)
	{
		str = get_next_line(0);
		check_input(str);
	}
	
	return (0);
}
