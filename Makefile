# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/23 13:45:00 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# PATH
PUSH_SWAP_PATH	= ./src/swapper/
CHECKER_PATH	= ./src/checker/

$(NAME):
	make -C $(PUSH_SWAP_PATH)
	cp $(PUSH_SWAP_PATH)push_swap .
	make -C $(CHECKER_PATH)
	cp $(CHECKER_PATH)checker .

all: $(NAME)

clean:
	make -C $(PUSH_SWAP_PATH) clean
	make -C $(CHECKER_PATH) clean

fclean: clean
	make -C $(PUSH_SWAP_PATH) fclean
	make -C $(CHECKER_PATH) fclean
	$(RM) push_swap checker

re: fclean all

.PHONY: all clean fclean re
