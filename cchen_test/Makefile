# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 11:19:44 by cchen             #+#    #+#              #
#    Updated: 2022/05/10 20:43:25 by jniemine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test_printf
PRINTF_DIR := /Users/jniemine/Workspace/ft_printf/ft_printf/
FT_PRINTF := libftprintf.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I$(PRINTF_DIR)/libft -I$(PRINTF_DIR)/includes -I./includes
LIB :=  -L$(PRINTF_DIR) -lftprintf

SRC_DIR := ./src
SRC := $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(SRC) -o $@

clean:
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all


