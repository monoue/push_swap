# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/25 16:26:38 by monoue           ###   ########.fr        #
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

BASE	  = $(COMMON_PATH)args_are_integers_bonus.c \
			$(COMMON_PATH)args_are_valid_bonus.c \
			$(COMMON_PATH)basic_list_operations1_bonus.c \
			$(COMMON_PATH)basic_list_operations2_bonus.c \
			$(COMMON_PATH)get_sorted_array_bonus.c \
			$(COMMON_PATH)get_struct_list_bonus.c \
			$(COMMON_PATH)init_stacks_bonus.c \
			$(COMMON_PATH)is_valid_operator_bonus.c \
			$(COMMON_PATH)quick_sort_bonus.c \
			$(OPERATION_PATH)swap_bonus.c \
			$(OPERATION_PATH)rotate_bonus.c \
			$(OPERATION_PATH)reverse_rotate_bonus.c \
			$(OPERATION_PATH)push_bonus.c \
			$(SRC_PATH)bring_target_index_to_top_bonus.c \
			$(SRC_PATH)deal_chunk_range_bonus.c \
			$(SRC_PATH)exec_bonus.c \
			$(SRC_PATH)exec2_bonus.c \
			$(SRC_PATH)exec_two_bonus.c \
			$(SRC_PATH)exec_three_bonus.c \
			$(SRC_PATH)exec_four_or_five_bonus.c \
			$(SRC_PATH)exec_and_put_operation_bonus.c \
			$(SRC_PATH)get_chunk_size_bonus.c \
			$(SRC_PATH)get_fore_or_back_target_index_bonus.c \
			$(SRC_PATH)get_index_of_largest_num_bonus.c \
			$(SRC_PATH)get_nearer_distance_bonus.c \
			$(SRC_PATH)get_nearness_bonus.c \
			$(SRC_PATH)get_nth_smallest_num_index_bonus.c \
			$(SRC_PATH)get_num_of_target_index_bonus.c \
			$(SRC_PATH)get_rotation_type_and_num_a_bonus.c \
			$(SRC_PATH)get_rotation_type_and_num_b_bonus.c \
			$(SRC_PATH)get_zero_rotation_bonus.c \
			$(SRC_PATH)is_sorted_bonus.c \
			$(SRC_PATH)rotate_based_on_info_bonus.c


SRCS = $(BASE) $(SRC_PATH)main_bonus.c

OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:.c=.d)
LIBFT	= $(LIBFT_PATH)libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $@ $^

debug: $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -o $@ $^

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
