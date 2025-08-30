# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdhal <sdhal@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 19:28:14 by ldick             #+#    #+#              #
#    Updated: 2025/08/30 19:07:19 by sdhal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit.a
TEST_BIN = run_tests

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

FRAMEWORK_SRC = framework/libunit.c framework/libunit_utils.c
FRAMEWORK_OBJ = $(FRAMEWORK_SRC:.c=.o)

#################################################################################################
#											Rules												#
#################################################################################################

all:			$(NAME)

$(NAME): $(FRAMEWORK_OBJ)
		@ar rcs $(NAME) $(FRAMEWORK_OBJ)
		@echo "$(GREEN)Static library $(NAME) created.$(NC)"

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME) $(FUNCTIONS_OBJ) $(TEST_OBJ)
		@make -C tests test --silent

clean:
				@make -C tests clean --silent
				@rm -rf $(FRAMEWORK_OBJ) $(FUNCTIONS_OBJ) $(TEST_OBJ)
				@rm -f $(ERROR_FILE)

fclean:			clean
				@make -C tests fclean --silent
				@rm -f $(NAME) $(TEST_BIN)

re:				fclean all

.PHONY:			all clean fclean re