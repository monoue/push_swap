/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:54:01 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 14:13:01 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"
#include "libft.h"
#include "defs.h"
#include "operation.h"

void		exec(t_num **stack_a, size_t nums_num, int sorted_array[])
{
	if (is_sorted(*stack_a))
		;
	else if (nums_num == 2)
		exec_two(*stack_a);
	else if (nums_num == 3)
		exec_three(stack_a);
	else if (nums_num < 6)
		exec_four_or_five(stack_a);
	else
		exec2(stack_a, nums_num, sorted_array);
}
