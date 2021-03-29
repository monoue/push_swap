# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <monoue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/29 10:39:06 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# PATH
LIBFT_PATH		= ../../lib/
COMMON_PATH	= ../common/
SRC_PATH	= ./src/
OPERATION_PATH = $(COMMON_PATH)operation/

INCLUDE	= -I../../lib -I../includes/ -I./includes

BASE	  = $(COMMON_PATH)args_has_empty.c \
			$(COMMON_PATH)args_are_integers.c \
			$(COMMON_PATH)args_are_valid.c \
			$(COMMON_PATH)basic_list_operations1.c \
			$(COMMON_PATH)basic_list_operations2.c \
			$(COMMON_PATH)get_sorted_array.c \
			$(COMMON_PATH)get_struct_list.c \
			$(COMMON_PATH)init_stacks.c \
			$(COMMON_PATH)is_valid_operator.c \
			$(COMMON_PATH)quick_sort.c \
			$(OPERATION_PATH)swap.c \
			$(OPERATION_PATH)rotate.c \
			$(OPERATION_PATH)reverse_rotate.c \
			$(OPERATION_PATH)push.c \
			$(SRC_PATH)bring_target_index_to_top.c \
			$(SRC_PATH)deal_chunk_range.c \
			$(SRC_PATH)exec.c \
			$(SRC_PATH)exec2.c \
			$(SRC_PATH)exec_two.c \
			$(SRC_PATH)exec_three.c \
			$(SRC_PATH)exec_four_or_five.c \
			$(SRC_PATH)exec_and_put_operation.c \
			$(SRC_PATH)get_chunk_size.c \
			$(SRC_PATH)get_fore_or_back_target_index.c \
			$(SRC_PATH)get_index_of_largest_num.c \
			$(SRC_PATH)get_nearer_distance.c \
			$(SRC_PATH)get_nearness.c \
			$(SRC_PATH)get_nth_smallest_num_index.c \
			$(SRC_PATH)get_num_of_target_index.c \
			$(SRC_PATH)get_rotation_type_and_num_a.c \
			$(SRC_PATH)get_rotation_type_and_num_b.c \
			$(SRC_PATH)get_zero_rotation.c \
			$(SRC_PATH)is_sorted.c \
			$(SRC_PATH)rotate_based_on_info.c


SRCS = $(BASE) $(SRC_PATH)main.c

OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:.c=.d)
LIBFT	= $(LIBFT_PATH)libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $@ $^

-include $(DEPS)

$(LIBFT):
	make -C $(LIBFT_PATH)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
