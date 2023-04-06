/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:54:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/06 13:28:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* library */
# include "../libft/libft.h"

typedef struct s_tools
{
	int	max;
}		t_tools;

/* sources */
int		main(int argc, char **argv);
int		find_biggest(t_list *stack);
int		find_smallest(t_list *stack);
void	simplified_stack(t_list **head);
t_list	*parsing_argv(int argc, char **argv);

/* sorting */
void	sort_five(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_big(t_list **stack_a, t_tools aid);

/* utils sorting */
void	init_moves(t_list *stack_b);
int		find_least_moves(t_list *stack_b);
int		get_least(t_list *stack, int min_moves);
int		get_best_a(t_list *stack_a, int b_index);
int		best_index(t_list *stack_a, t_list *stack_b);
void	moves_count_b(t_list *stack_b, t_list *current);
void	moves_count_a(t_list **stack_a, t_list *stack_b);
int		find_sup_index(int best_index, t_list *stack_a);
int		locate_index(t_list **stack, int index);
int		get_rotate_dir(t_list *stack, int loc);
void	sync_rotate_top(t_list **a, t_list **b, int index, int sup_index);
void	get_index_top(t_list **stack, int index, char c);

/* movements a stack & b stack */
void	do_swap(t_list **stack, char *str);
void	do_rotate(t_list **head, char c);
void	do_revrotate(t_list **head, char c);
void	do_push(t_list **stack1, t_list **stack2, char *str);
void	do_rr(t_list **stack_a, t_list **stack_b, char *str);
void	do_rrr(t_list **stack_a, t_list **stack_b, char *str);
void	do_ss(t_list **stack_a, t_list **stack_b, char *str);

/* error management */
void	ft_error(void);
int		check_number(char *str);
void	check_order(t_list *stack_a);
void	check_duplicates(t_list *stack_a);

/* print_list NOT TO BE PUSHED */
void	print_index(t_list *list);
void	print_list(t_list *list, char *str);
void	print_moves(t_list *list, char *str);

#endif
