/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:44:08 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:16:55 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "defs_bonus.h"

void	put_result(t_num *stack_a, bool stack_b_is_empty, size_t nums_num,
															char **nums_strs);
// void	read_and_exec_operations(t_num **stack_a, t_num **stack_b);
void	read_and_exec_operations(t_stacks *stacks);

#endif
