# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monoue <monoue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:33:41 by monoue            #+#    #+#              #
#    Updated: 2021/03/29 09:29:14 by monoue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# PATH
PUSH_SWAP_PATH	= ./src/swapper/
CHECKER_PATH	= ./src/checker/
BONUS_PUSH_SWAP_PATH	= ./bonus/swapper/
BONUS_CHECKER_PATH	= ./bonus/checker/

$(NAME):
	make -C $(PUSH_SWAP_PATH)
	cp $(PUSH_SWAP_PATH)push_swap .
	make -C $(CHECKER_PATH)
	cp $(CHECKER_PATH)checker .

bonus:
	make -C $(BONUS_PUSH_SWAP_PATH)
	cp $(BONUS_PUSH_SWAP_PATH)push_swap .
	make -C $(BONUS_CHECKER_PATH)
	cp $(BONUS_CHECKER_PATH)checker .

all: $(NAME)

clean:
	make -C $(PUSH_SWAP_PATH) clean
	make -C $(CHECKER_PATH) clean
	make -C $(BONUS_PUSH_SWAP_PATH) clean
	make -C $(BONUS_CHECKER_PATH) clean

fclean: clean
	make -C $(PUSH_SWAP_PATH) fclean
	make -C $(CHECKER_PATH) fclean
	make -C $(BONUS_PUSH_SWAP_PATH) fclean
	make -C $(BONUS_CHECKER_PATH) fclean
	$(RM) push_swap checker

re: fclean all

.PHONY: all clean fclean re bonus
