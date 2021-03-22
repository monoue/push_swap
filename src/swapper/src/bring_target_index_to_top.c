/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_target_index_to_top.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 07:18:56 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 08:39:19 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

static void	set_end_and_func(size_t nums_num, size_t target_index, size_t *end,
																t_op_func *func)
{
	if (target_index <= nums_num / 2)
	{
		*end = target_index;
		*func = rotate_designated;
	}
	else
	{
		if (nums_num < target_index)
			*end = 0;
		else
			*end = nums_num - target_index;
		*func = reverse_rotate_designated;
	}
}

void		bring_target_index_to_top(t_num **stack_a, t_num **stack_b,
											size_t target_index, int stack_type)
{
	size_t		nums_num;
	size_t		index;
	size_t		end;
	t_op_func	func;

	if (target_index == 0)
		return ;
	if (stack_type == STACK_A)
		nums_num = lstsize(*stack_a);
	else
		nums_num = lstsize(*stack_b);
	set_end_and_func(nums_num, target_index, &end, &func);
	index = 0;
	while (index < end)
	{
		exec_and_put_operation(stack_a, stack_b, func, stack_type);
		index++;
	}
}
