/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:53:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/12 11:17:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	free_lst(t_list **a)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

int	main(int argc, char **argv)
{
	int		len;
	t_tools	aid;
	t_list	*stack_a;

	len = 0;
	aid.max = 0;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_argv(argc, argv);
	check_duplicates(stack_a);
	check_order(stack_a);
	simplified_stack(&stack_a);
	len = ft_lstsize(stack_a);
	if (len <= 3)
		sort_three(&stack_a);
	else if (len > 3 && len <= 5)
		sort_five(&stack_a);
	else
		sort_big(&stack_a, aid);
	free_lst(&stack_a);
	return (0);
}
