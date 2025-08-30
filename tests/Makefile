# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldick <ldick@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 19:28:14 by ldick             #+#    #+#              #
#    Updated: 2025/08/30 17:47:32 by ldick            ###   ########.fr        #
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

TEST_SRCS = ../main.c strlen/00_launcher.c strlen/01_basic_test.c strlen/02_null_test.c strlen/03_very_long_line_test.c strlen/04_not_null_terminated_test.c
FUNCTION_SRCS = ../functions/ft_strlen.c
SRCS = $(TEST_SRCS) $(FUNCTION_SRCS)

OBJS = $(SRCS:.c=.o) $(FUNCTION_SRCS.c=.o)

#################################################################################################
#											Rules												#
#################################################################################################

all:			$(NAME)

$(NAME): ../libunit.a $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) ../libunit.a -o $(NAME)
		@echo "$(GREEN)test routine $(NAME) created.$(NC)"

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@rm -rf $(OBJS)
				@rm -f $(ERROR_FILE)

fclean:			clean
				@rm -f $(NAME) $(TEST_BIN)

re:				fclean all

test: re
	-./$(NAME)

.PHONY:			all clean fclean re