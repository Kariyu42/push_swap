# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:22:37 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/06 17:05:52 by kquetat-         ###   ########.fr        #
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
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[PUSH_SWAP] => $(RESET)""$(GRAY) $< \033[K\r$(RESET)"

RM	=	rm -f

### Colors ###
VIOLET		=\033[0;35m
GRAY		=\033[0;37m
OGREEN		=\033[0;32m
SKYBLUE		=\033[0;36m
BEIGE		=\033[38;5;223m
BOLD		=\033[1m
RESET		=\033[0m
ITALIC		=\033[3m

### Debug ###
ifdef DEBUG
CFLAGS	+=	-fsanitize=address -g3
endif

### Source files ###
SRCS	=	${addprefix ${SRCS_PATH}, ft_error.c ft_moves.c ft_counter.c \
			ft_parsing.c sort_small.c utils.c sort_big.c double_moves.c \
			big_utils.c main.c}

OBJS	=	$(SRCS:.c=.o)
### Rules ###
all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)PUSH_SWAP files compiled$(RESET) ✨\n\n"
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(OGREEN)$(BOLD)[LIBFT] $(RESET)\n"
	@make bonus -C $(LIBFT)
	@printf "\n\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)PUSH_SWAP COMPILED$(RESET) ✅\n"

bonus:

debug:
	$(MAKE) DEBUG=1

clean:
	@$(RM) $(OBJS)
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)PUSH_SWAP files removed$(RESET) ...\n\n"
	@make clean -C $(LIBFT)
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)LIBFT files removed$(RESET) ...\n\n"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)libft.a
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)PUSH_SWAP binary removed$(RESET) ...\n\n"

re:		fclean all

.PHONY:	all debug clean fclean re