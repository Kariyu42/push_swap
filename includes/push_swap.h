/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:54:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/16 15:31:44 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* library */
# include "../libft/libft.h"

/* sources */
int		main(int argc, char **argv);
t_list	*parsing_argv(int argc, char **argv);
void	simplified_stack(t_list **head);
/* sorting */
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a);

/* movements a stack & b stack */
void	do_rotate(t_list **head);
void	do_swap(t_list **stack);
void	do_revrotate(t_list **head);
void	do_push(t_list **stack1, t_list **stack2);

/* error management */
void	ft_error(void);
int		check_number(char *str);
void	check_duplicates(t_list *stack_a);
void	check_order(t_list *stack_a);

/* print_list NOT TO BE PUSHED */
void	print_list(t_list *list);

#endif
