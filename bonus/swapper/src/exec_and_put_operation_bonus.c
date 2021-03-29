/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_put_operation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:55:13 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 09:41:51 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static void	deal_debug_info(t_stacks *stacks)
{
	t_flags	*flags;

	flags = stacks->flags;
	if (flags->total_count_flag)
		stacks->counts->total_count++;
	if (flags->frame_flag || flags->nums_in_stacks_flag)
		put_status(stacks);
}

void		exec_and_put_operation(t_stacks *stacks, t_op_func func,
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
	func(stacks, stack_type);
	deal_debug_info(stacks);
}
