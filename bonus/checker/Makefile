# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <monoue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/29 09:37:17 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# PATH
LIBFT_PATH		= ../../lib/
COMMON_PATH	= ../common/
OPERATION_PATH = $(COMMON_PATH)operation/
SRC_PATH	= ./src/


INCLUDE	= -I../../lib -I../includes/ -I./includes/

BASE	  = $(COMMON_PATH)args_are_integers_bonus.c \
			$(COMMON_PATH)args_are_valid_bonus.c \
			$(COMMON_PATH)basic_list_operations1_bonus.c \
			$(COMMON_PATH)basic_list_operations2_bonus.c \
			$(COMMON_PATH)get_option_strs_num_bonus.c \
			$(COMMON_PATH)get_sorted_array_bonus.c \
			$(COMMON_PATH)get_struct_list_bonus.c \
			$(COMMON_PATH)init_stacks_bonus.c \
			$(COMMON_PATH)is_valid_operator_bonus.c \
			$(COMMON_PATH)quick_sort_bonus.c \
			$(OPERATION_PATH)push_bonus.c \
			$(OPERATION_PATH)reverse_rotate_bonus.c \
			$(OPERATION_PATH)rotate_bonus.c \
			$(OPERATION_PATH)swap_bonus.c \
			$(SRC_PATH)put_result_bonus.c \
			$(SRC_PATH)read_and_exec_operations_bonus.c



SRCS = $(BASE) $(SRC_PATH)main_bonus.c

OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:.c=.d)
LIBFT	= $(LIBFT_PATH)libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $@ $^

debug: $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -o $(NAME) $^

-include $(DEPS)

$(LIBFT):
	make -C $(LIBFT_PATH)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) debug
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
