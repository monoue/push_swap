# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/04 16:52:24 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# PATH
SRCS_PATH		= src/
LIBFT_PATH		= libft/
PUSH_SWAP_PATH	= push_swap/
CHECKER_PATH	= checker/

INCLUDE	= -I./libft -I./src/includes

BASE	  = $(CHECKER_PATH)args_are_unique.c \
			$(CHECKER_PATH)args_are_valid.c \
			$(CHECKER_PATH)checker_main.c

SRCS_NAME = $(BASE)
TEST_NAME = $(BASE)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
TEST = $(addprefix $(SRCS_PATH), $(TEST_NAME))
OBJS = $(SRCS:%.c=%.o)
DEPS	= $(SRCS:.c=.d)
TOBJS = $(TEST:%.c=%.o)
LIBFT	= libft/libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -fsanitize=address -o $@ $^

-include $(DEPS)

$(LIBFT):
	make -C libft

all: $(NAME)

test: $(TOBJS) $(LIBFT)
	@$(CC) -o $@ $^

bonus: $(BOBJS)
	@$(MAKE) -C $(LIBFT_PATH);
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) test

re: fclean all

.PHONY: all clean fclean re run
