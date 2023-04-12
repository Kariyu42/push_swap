# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:22:37 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/12 10:22:32 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of binary push_swap & checker ###
NAME		=	push_swap
BONUS_NAME	=	checker
HEADER_F	=	includes/
LIBFT		=	libft/libft/
SRCS_PATH	=	srcs/main/
BONUS_PATH	=	./srcs/bonus/
GNL_DIR		=	libft/get_next_line/

### Compilation & flags ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[PUSH_SWAP] => $(RESET)""$(OGREEN) <$<> \033[K\r$(RESET)"

$(BONUS_PATH)%.o: $(BONUS_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[CHECKER] => $(RESET)""$(GRAY) <$<> \033[K\r$(RESET)"

$(GNL_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[CHECKER] => $(RESET)""$(GRAY) <$<> \033[K\r$(RESET)"

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

### Source files & Bonus files ###
SRCS	=	${addprefix ${SRCS_PATH}, sources/ft_error.c sources/ft_moves.c sources/ft_counter.c \
			sources/ft_parsing.c sources/sort_small.c sources/utils.c sources/sort_big.c sources/double_moves.c \
			sources/big_utils.c push_swap.c}

SRCS_BONUS	=	${addprefix ${BONUS_PATH}, bonus_srcs/error.c bonus_srcs/move_utils.c \
				bonus_srcs/move_utils2.c bonus_srcs/parsing.c checker.c} \
				${addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c}

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

### Rules ###
all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)PUSH_SWAP files compiled$(RESET) ✨\n\n"
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(OGREEN)$(BOLD)[LIBFT]$(RESET)\n"
	@make bonus -C $(LIBFT)
	@printf "\n\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)PUSH_SWAP COMPILED$(RESET) ✅\n"

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(OBJS_BONUS)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)Bonus Checker files compiled$(RESET) ✨\n\n"
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(OGREEN)$(BOLD)[LIBFT]$(RESET)\n"
	@make bonus -C $(LIBFT)
	@printf "\n\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)CHECKER COMPILED$(RESET) ✅\n"

debug:
	$(MAKE) DEBUG=1

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)PUSH_SWAP files removed$(RESET) ...\n\n"
	@make clean -C $(LIBFT)
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)LIBFT files removed$(RESET) ...\n\n"

fclean:	clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(RM) $(LIBFT)libft.a
	@printf "\n\t$(VIOLET)$(BOLD)$(ITALIC)PUSH_SWAP binary removed$(RESET) ...\n\n"

re:		fclean all

.PHONY:	all debug clean fclean bonus re