# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollon <acollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:45:35 by acollon           #+#    #+#              #
#    Updated: 2025/07/16 19:14:01 by acollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_BONUS	= checker

SRC_DIR	= src
SRC_BONUS = bonus
OBJ_DIR	= obj
INC_DIR	= includes
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

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

SRCS_BONUS	= \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		$(SRC_BONUS)/main_bonus.c \
		$(SRC_DIR)/stack_check.c \
		$(SRC_DIR)/stack_double_operation.c \
		$(SRC_DIR)/stack_operation.c \
		$(SRC_DIR)/stack_parsing.c \
		$(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/error_handling.c 

	
OBJS	= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -g
LIBFT	= $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	
bonus: $(NAME_BONUS)

$(NAME_BONUS):$(LIBFT) $(PRINTF) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
