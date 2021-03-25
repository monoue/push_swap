/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:54:01 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 16:29:03 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "libft.h"
#include "defs_bonus.h"
#include "operation_bonus.h"

void		exec(t_stacks *stacks, size_t nums_num, int sorted_array[])
{
	if (is_sorted(stacks->stack_a))
		;
	else if (nums_num == 2)
		exec_two(stacks);
	else if (nums_num == 3)
		exec_three(stacks);
	else if (nums_num < 6)
		exec_four_or_five(stacks);
	else
		exec2(stacks, nums_num, sorted_array);
}
