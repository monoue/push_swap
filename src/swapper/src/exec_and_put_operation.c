/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_put_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:55:13 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:47:35 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"
#include "libft.h"
#include "operation.h"

void	exec_and_put_operation(t_num **stack_a, t_num **stack_b, t_op_func func,
																int stack_type)
{
	const t_op_func_set2	sets[] = {
		{"sa", &swap_designated, STACK_A}, {"sb", &swap_designated, STACK_B},
		{"ss", &swap_designated, DOUBLE}, {"pa", &push_designated, STACK_A},
		{"pb", &push_designated, STACK_B}, {"ra", &rotate_designated, STACK_A},
		{"rb", &rotate_designated, STACK_B}, {"rr", &rotate_designated, DOUBLE},
		{"rra", &reverse_rotate_designated, STACK_A},
		{"rrb", &reverse_rotate_designated, STACK_B},
		{"rrr", &reverse_rotate_designated, DOUBLE}, {NULL, NULL, STACKS_NUM}
	};
	t_op_func_set2			set;
	size_t					index;

	index = 0;
	while (sets[index].str)
	{
		set = sets[index];
		if (set.func == func && set.stack_type == stack_type)
		{
			ft_putendl(set.str);
			break ;
		}
		index++;
	}
	func(stack_a, stack_b, stack_type);
}
