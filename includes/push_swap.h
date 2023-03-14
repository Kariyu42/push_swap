/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:54:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/13 12:33:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* library */
# include "../libft/libft.h"

/* sources */
int		main(int argc, char **argv);
t_list	*parsing_argv(int argc, char **argv);
/* sorting */
void	sort_three(t_list **stack_a);
/* movements a stack */
void	do_sa(t_list **stack);
void	do_pa(t_list **a, t_list **b);
void	do_ra(t_list **head);
void	do_rra(t_list **head);
/* movements b stack */

/* error management */
void	ft_error(void);
int		check_number(char *str);
void	check_duplicates(t_list *stack_a);
void	check_order(t_list *stack_a);

#endif
