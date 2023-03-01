/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:54:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/03/01 17:10:47 by kquetat-         ###   ########.fr       */
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
	struct s_node	*previous;
}				t_node;

/* sources */
int		main(int argc, char **argv);
t_node	*parsing_argv(int argc, char **argv);
t_node	*new_node(int data);
void	add_node_back(t_node **ptr, t_node *new_node);

/* error management */
void	ft_error(void);

#endif
