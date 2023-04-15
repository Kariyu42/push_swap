/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:34 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/15 16:36:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

static int	recheck_order(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->nbr < tmp->next->nbr)
			tmp = tmp->next;
		else
			return (INVALID);
	}
	return (VALID);
}

static int	input_scan(char *str, t_list **a, t_list **b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		do_swap(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		do_swap(b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		do_ss(a, b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		do_rotate(a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		do_rotate(b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		do_rr(a, b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		do_revrotate(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		do_revrotate(b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		do_rrr(a, b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		do_push(b, a, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		do_push(a, b, 0);
	else
		return (INVALID);
	return (VALID);
}

static void	read_entry(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (input_scan(line, a, b) == INVALID)
			ft_error();
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parsing_bonus(argc, argv);
	dup_bonus(stack_a);
	read_entry(&stack_a, &stack_b);
	if (recheck_order(stack_a) == VALID && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_lst(&stack_a);
	return (0);
}
