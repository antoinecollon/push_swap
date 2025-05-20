# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:45:35 by acollon           #+#    #+#              #
#    Updated: 2025/05/10 11:08:06 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= includes
LIBFT_DIR = libft

SRCS	= \
	$(SRC_DIR)/cheapest_logic.c \
	$(SRC_DIR)/error_handling.c \
	$(SRC_DIR)/execution.c \
	$(SRC_DIR)/pos_and_index.c \
	$(SRC_DIR)/sorting_small.c \
	$(SRC_DIR)/sorting_small_utils.c \
	$(SRC_DIR)/stack_check.c \
	$(SRC_DIR)/stack_double_operation.c \
	$(SRC_DIR)/stack_operation.c \
	$(SRC_DIR)/stack_parsing.c \
	$(SRC_DIR)/stack_utils.c \

OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT	= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
