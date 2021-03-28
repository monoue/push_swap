# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <monoue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/29 07:51:11 by monoue           ###   ########.fr        #
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

BASE	  = $(COMMON_PATH)args_are_integers.c \
			$(COMMON_PATH)args_are_valid.c \
			$(COMMON_PATH)basic_list_operations1.c \
			$(COMMON_PATH)basic_list_operations2.c \
			$(COMMON_PATH)get_sorted_array.c \
			$(COMMON_PATH)get_struct_list.c \
			$(COMMON_PATH)init_stacks.c \
			$(COMMON_PATH)is_valid_operator.c \
			$(COMMON_PATH)quick_sort.c \
			$(OPERATION_PATH)push.c \
			$(OPERATION_PATH)reverse_rotate.c \
			$(OPERATION_PATH)rotate.c \
			$(OPERATION_PATH)swap.c \
			$(SRC_PATH)put_result.c \
			$(SRC_PATH)read_and_exec_operations.c



SRCS = $(BASE) $(SRC_PATH)main.c

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

	# $(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) debug

	# $(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
