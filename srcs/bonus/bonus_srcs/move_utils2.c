/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:23:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/11 15:53:06 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	do_ss(t_list **stack_a, t_list **stack_b, char *str)
{
	do_swap(stack_a, 0);
	do_swap(stack_b, 0);
	ft_putstr_fd(str, 1);
}

void	do_rr(t_list **stack_a, t_list **stack_b, char *str)
{
	do_rotate(stack_a, 0);
	do_rotate(stack_b, 0);
	ft_putstr_fd(str, 1);
}

void	do_rrr(t_list **stack_a, t_list **stack_b, char *str)
{
	do_revrotate(stack_a, 0);
	do_revrotate(stack_b, 0);
	ft_putstr_fd(str, 1);
}
