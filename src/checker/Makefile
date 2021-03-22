# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/22 16:33:39 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# PATH
LIBFT_PATH		= ../../lib/
COMMON_PATH	= ../common/
TEST_PATH	= $(COMMON_PATH)test/
OPERATION_PATH = $(COMMON_PATH)operation/
SRC_PATH	= ./src/


INCLUDE	= -I../../lib -I../includes/ -I./includes/

BASE	  = $(COMMON_PATH)args_are_integers.c \
			$(COMMON_PATH)args_are_valid.c \
			$(COMMON_PATH)basic_list_operations.c \
			$(COMMON_PATH)get_sorted_array.c \
			$(COMMON_PATH)get_struct_list.c \
			$(COMMON_PATH)is_valid_operator.c \
			$(COMMON_PATH)quick_sort.c \
			$(OPERATION_PATH)push.c \
			$(OPERATION_PATH)reverse_rotate.c \
			$(OPERATION_PATH)rotate.c \
			$(OPERATION_PATH)swap.c \
			$(SRC_PATH)put_result.c \
			$(SRC_PATH)read_and_exec_operations.c

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
