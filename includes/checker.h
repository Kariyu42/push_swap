/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:29:04 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/14 14:26:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define VALID 0
# define INVALID 1

/* libraries */
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include <limits.h>

/* bonus files */
t_list	*parsing_bonus(int argc, char **argv);
/* error management */
void	free_split_bonus(char **tmp);
void	dup_bonus(t_list *stack_a);
void	ft_error(void);
int		check_number_bonus(char *str);
/* moves */
void	do_swap(t_list **stack, char *str);
void	do_push(t_list **stack1, t_list **stack2, char *str);
void	do_rotate(t_list **head, char c);
void	do_revrotate(t_list **head, char c);
/* double moves */
void	do_ss(t_list **stack_a, t_list **stack_b, char *str);
void	do_rr(t_list **stack_a, t_list **stack_b, char *str);
void	do_rrr(t_list **stack_a, t_list **stack_b, char *str);

#endif
