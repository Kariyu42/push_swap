# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:22:37 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/06 07:50:26 by kquetat-         ###   ########.fr        #
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
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(PALEBLUE)$(BOLD)$(ITALIC)Loading: $(RESET)""$(LGREEN)<$<> \033[K\r$(RESET)"

RM		=	rm -f

### Colors ###
PALEBLUE	=\033[38;5;153m
ITALIC		=\033[3m
BOLD		=\033[1m
BEIGE		=\033[38;5;223m
LRED		=\033[91m
LGREEN		=\033[1;32m
SOFTPINK	=\033[38;5;224m
RESET		=\033[0m

### Debug ###
ifdef DEBUG
CFLAGS	+=	-fsanitize=address -g3
endif

### Source files ###
SRCS	=	${addprefix ${SRCS_PATH}, ft_error.c \
										ft_moves.c \
										ft_counter.c \
										ft_parsing.c \
										sort_small.c \
										utils.c \
										sort_big.c \
										double_moves.c \
										main.c}

OBJS	=	$(SRCS:.c=.o)
### Rules ###
all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "$(BEIGE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(SOFTPINK)$(BOLD)[PUSH_SWAP]$(RESET)"
	@printf "\n"
	@echo "$(BEIGE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(SOFTPINK)$(BOLD)[LIBFT]$(RESET)"
	@printf "\n"
	@make bonus -C $(LIBFT)
	@printf "\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "\n\n"
	@echo "$(BOLD)$(ITALIC)$(LGREEN)PUSH_SWAP COMPILED$(RESET) 🪴"

bonus:

debug:
	$(MAKE) DEBUG=1

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)libft.a

re:		fclean all

.PHONY:	all debug clean fclean re