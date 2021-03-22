# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/22 09:38:47 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# PATH
LIBFT_PATH		= ../../lib/
COMMON_PATH	= ../common/
TEST_PATH	= $(COMMON_PATH)test/
SRC_PATH	= ./src/
OPERATION_PATH = $(COMMON_PATH)operation/

INCLUDE	= -I../../lib -I../includes/ -I./includes

BASE	  = $(COMMON_PATH)args_are_unique.c \
			$(COMMON_PATH)args_are_valid.c \
			$(COMMON_PATH)basic_list_operations.c \
			$(COMMON_PATH)get_sorted_array.c \
			$(COMMON_PATH)get_struct_list.c \
			$(COMMON_PATH)is_valid_operator.c \
			$(COMMON_PATH)quick_sort.c \
			$(OPERATION_PATH)swap.c \
			$(OPERATION_PATH)rotate.c \
			$(OPERATION_PATH)reverse_rotate.c \
			$(OPERATION_PATH)push.c \
			$(SRC_PATH)bring_target_index_to_top.c \
			$(SRC_PATH)exec.c \
			$(SRC_PATH)exec_two.c \
			$(SRC_PATH)exec_three.c \
			$(SRC_PATH)exec_four_or_five.c \
			$(SRC_PATH)exec_one_hundred_or_less.c \
			$(SRC_PATH)exec_and_put_operation.c \
			$(SRC_PATH)get_nearer_index.c \
			$(SRC_PATH)get_num_of_target_index.c \
			$(SRC_PATH)get_rotation_type_and_num.c \
			$(SRC_PATH)get_zero_rotation.c \
			$(SRC_PATH)is_sorted.c

TEST_FILES = test_main.c \
				$(TEST_PATH)test_functions.c


SRCS = $(BASE) $(SRC_PATH)main.c $(TEST_PATH)test_functions.c
TEST = $(BASE) $(TEST_FILES)

OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:.c=.d)
TOBJS = $(TEST:%.c=%.o)
LIBFT	= $(LIBFT_PATH)libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -o $@ $^

-include $(DEPS)

$(LIBFT):
	make -C $(LIBFT_PATH)

all: $(NAME)

test: $(TOBJS) $(LIBFT)
	@$(CC) -o $@ $^

bonus: $(BOBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

# $(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) test

# $(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re run bonus
