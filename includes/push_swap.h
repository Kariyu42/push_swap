/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:54:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/10 18:10:19 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* library */
# include "../libft/libft.h"
/* struct */
typedef struct s_node
{
	int				num;
	struct s_node	*next;
}				t_node;

/* sources */
int		main(int argc, char **argv);
t_node	*parsing_argv(int argc, char **argv);
t_node	*new_node(int data);
void	add_node_back(t_node **ptr, t_node *new_node);
int		node_size(t_node *stack);
t_node	*sort_small_stack(t_node *stack_a);
void	do_sa(t_node **stack);

/* error management */
void	ft_error(void);
int		check_number(char *str);
void	check_duplicates(t_node *stack_a);
void	check_order(t_node *stack_a);

#endif
