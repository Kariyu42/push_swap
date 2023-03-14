# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:22:37 by kquetat-          #+#    #+#              #
#    Updated: 2023/03/13 18:33:42 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of binary ###
NAME		=	push_swap
HEADER_F	=	includes/
LIBFT		=	libft/
SRCS_PATH	=	srcs/

### Compilation & flags ###
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

ifdef DEBUG
CFLAGS	+=	-fsanitize=address -g3
endif

### Source files ###

SRCS	=	${addprefix ${SRCS_PATH}, ft_error.c \
										ft_moves.c \
										ft_parsing.c \
										ft_sorting.c \
										main.c}

OBJS	=	$(SRCS:.c=.o)
### Rules ###
all:	$(NAME)

$(NAME):	$(OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a

debug:
	$(MAKE) DEBUG=1

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)libft.a

re:		fclean all

.PHONY:	all debug clean fclean re