/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:34:07 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:33:46 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# include "defs_bonus.h"

bool			args_are_integers(size_t argc, char *argv[]);
bool			args_are_valid(size_t argc, char *argv[]);
t_num			*get_struct_list(size_t args_num, char **num_strs);
bool			is_valid_operator(char *str);

/*
** quick sort
*/
void			quick_sort(int array[], int left, int right, size_t nums_num);
void			get_sorted_array(int *array, size_t num, char **strs);

/*
** list operation
*/
t_num			*lstlast(t_num *stack);
void			lstadd_back(t_num **stack, t_num *new);
t_num			*lstnew(int num);
size_t			lstsize(t_num *stack);
void			lstdel(t_num *stack);
void			lstdel_front(t_num **stack);
void			lstdel_back(t_num **stack);
void			lstadd_front(t_num **stack, t_num *new);
void			stacks_del(t_stacks *stacks);
t_stacks		*init_stacks(void);
#endif
