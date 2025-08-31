# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldick <ldick@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 19:28:14 by ldick             #+#    #+#              #
#    Updated: 2025/08/31 15:35:26 by ldick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unit_test

#################################################################################################
#											Colors												#
#################################################################################################

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
BOLD_BLUE	:= \033[0;34m
NC			:= \033[0m

#################################################################################################
#											Flags												#
#################################################################################################

COMPILER	=	cc
CFLAGS		=	-g -Wall -Wextra -Werror #-fsanitize=address
ERROR_FILE	=	error.log

#################################################################################################
#											Sources												#
#################################################################################################


TEST_SRCS = ../main.c ft_atoi/00_launcher.c ft_atoi/01_basic_test.c ft_atoi/02_over_max_int.c ft_atoi/03_under_min_int.c ft_atoi/04_not_number.c ft_atoi/05_str_is_null.c ft_atoi/06_bus_error_test.c ft_atoi/07_negative_number.c ft_atoi/08_numbers_and_chars.c ft_atoi/09_whitespaces.c ft_atoi/10_hex.c ft_atoi/11_empty_str.c ft_atoi/12_int_max.c ft_atoi/13_int_min.c ft_atoi/14_invalid_sequence.c ft_atoi/15_only_whitespace.c ft_atoi/16_space_between_sign_and_digit.c ../ft_atoi_helper_bus.c
SRCS = $(TEST_SRCS)

OBJS = $(SRCS:.c=.o)

#################################################################################################
#											Libft												#
#################################################################################################

LIBFT_DIR = ../functions/libft
LIBFT = $(LIBFT_DIR)/libft.a

#################################################################################################
#											Rules												#
#################################################################################################

all:			$(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --silent

$(NAME): ../libunit.a $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) ../libunit.a $(LIBFT) -o $(NAME)
		@echo "$(GREEN)test routine $(NAME) created.$(NC)"

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@rm -rf $(OBJS)
				@rm -f $(ERROR_FILE)
				@make -C $(LIBFT_DIR) clean --silent

fclean:			clean
				@rm -f $(NAME) $(TEST_BIN)
				@make -C $(LIBFT_DIR) fclean --silent

re:				fclean all

test: re
	-./$(NAME)

.PHONY:			all clean fclean re