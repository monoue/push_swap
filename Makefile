# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/18 06:51:49 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME2 = checker
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# PATH
SRCS_PATH		= src/
LIBFT_PATH		= libft/
PUSH_SWAP_PATH	= push_swap/
CHECKER_PATH	= checker/
COMMON_PATH	= common/

INCLUDE	= -I./libft -I./src/includes

BASE	  = $(COMMON_PATH)args_are_unique.c \
			$(COMMON_PATH)args_are_valid.c \
			$(COMMON_PATH)read_and_exec_operations.c \
			$(COMMON_PATH)basic_list_operations.c \
			$(COMMON_PATH)get_sorted_array.c \
			$(COMMON_PATH)get_struct_list.c \
			$(COMMON_PATH)is_valid_operator.c \
			$(COMMON_PATH)quick_sort.c \
			$(COMMON_PATH)put_result.c \
			$(COMMON_PATH)swap.c \
			$(COMMON_PATH)rotate.c \
			$(COMMON_PATH)reverse_rotate.c \
			$(COMMON_PATH)push.c \

SRCS_NAME = $(BASE) $(CHECKER_PATH)main.c
TEST_NAME = $(BASE) test.c test_functions.c

C_SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
TEST = $(addprefix $(SRCS_PATH), $(TEST_NAME))
C_OBJS = $(C_SRCS:%.c=%.o)
DEPS	= $(C_SRCS:.c=.d)
TOBJS = $(TEST:%.c=%.o)
LIBFT	= libft/libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME1): $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -o $@ $^

-include $(DEPS)

$(LIBFT):
	make -C libft

all: $(NAME1)

ps: $(OBJS) $(LIBFT)
	$(CC) -fsanitize=address -o push_swap $^

checker: $(OBJS) $(LIBFT)
	$(CC) -fsanitize=address -o checker $^

test: $(TOBJS) $(LIBFT)
	@$(CC) -o $@ $^

bonus: $(BOBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $(NAME1)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) test

re: fclean all

.PHONY: all clean fclean re run
