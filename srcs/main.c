/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/02 16:14:43 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	
	int i = 1;
	while (stack_a)
	{
		printf("[%d]---> ", stack_a->num);
		stack_a = stack_a->next;
		i++;
	}
	printf("NULL\n");
	return (0);
}
