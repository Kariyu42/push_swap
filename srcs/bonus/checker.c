/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:26:34 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/11 18:44:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "stdio.h"

static void	print_list(t_list *a)
{
	t_list *tmp = a;
	while (tmp)
	{
		printf("[%d]--> ", tmp->nbr);
		tmp = tmp->next;
	}
}

static int	recheck_order(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	printf("tmp:\n");
	print_list(tmp);
	while (tmp && tmp->next != NULL)
	{
		if (tmp->nbr < tmp->next->nbr)
		{
			puts("aaaaaaa");
			tmp = tmp->next;
		}
		else
		{
			puts("aaasa sale pute");
			return (INVALID);
		}
	}
	return (VALID);
}

static int	input_scan(char *str, t_list **a, t_list **b)
{
	if (!ft_strncmp(str, "sa\n", 3))
	{
		printf("je passse la!\n");
		do_swap(a, 0);
	}
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

static void read_entry(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	printf("gnl = %s\n", line);
	while (line > 0)
	{
		if (input_scan(line, a, b) == INVALID)
			ft_error();
		free(line);
		line = get_next_line(0);
	}
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
	print_list(stack_a);
	dup_bonus(stack_a);
	check_order_bonus(stack_a);
	read_entry(&stack_a, &stack_b);
	if (recheck_order(stack_a) == VALID)
		ft_putstr_fd("OK\n", 1);
	else if (recheck_order(stack_a) == INVALID && stack_b == NULL)
		ft_putstr_fd("KO\n", 1);
	print_list(stack_a);
	return (0);
}
