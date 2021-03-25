/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_chunk_range_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 16:23:23 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static size_t	get_nearer_index(size_t i1, size_t i2, size_t nums_num)
{
	const size_t	nearness1 = get_nearness(i1, nums_num);
	const size_t	nearness2 = get_nearness(i2, nums_num);

	if (nearness1 <= nearness2)
		return (i1);
	else
		return (nums_num - i2);
}

static size_t	get_nearest_target_index(t_num *stack_a, int chunk_max_nums[],
																size_t chunk_i)
{
	const size_t	nums_num = lstsize(stack_a);
	size_t			fore_index;
	size_t			back_index;

	fore_index = get_fore_target_index(stack_a, chunk_max_nums, chunk_i);
	back_index = get_back_target_index(stack_a, chunk_max_nums, chunk_i);
	return (get_nearer_index(fore_index, back_index, nums_num));
}

// static void		bring_largest_num_to_top(t_num **stack_a, t_num **stack_b,
static void		bring_largest_num_to_top(t_stacks *stacks,
																int stack_type)
{
	t_num	*stack;
	size_t	largest_num_i;

	if (stack_type == STACK_A)
		stack = stacks->stack_a;
	else if (stack_type == STACK_B)
		stack = stacks->stack_b;
	else
		stack = NULL;
	largest_num_i = get_index_of_largest_num(stack);
	bring_target_index_to_top(stacks, largest_num_i, stack_type);
}

// void			deal_chunk_range(t_num **stack_a, t_num **stack_b,
void			deal_chunk_range(t_stacks *stacks,
										int chunk_max_nums[], size_t chunk_i)
{
	bool			first_try;
	t_rotation_info	*a_rotation_info;
	t_rotation_info	*b_rotation_info;
	int				a_target_num;
	size_t			chunk_size;

	chunk_size = get_chunk_size(lstsize(stacks->stack_a) + lstsize(stacks->stack_b));
	first_try = true;
	while (stacks->stack_a && lstsize(stacks->stack_a)
							&& (first_try || lstsize(stacks->stack_b) % chunk_size))
	{
		first_try = false;
		a_rotation_info = get_rotation_type_and_num_a(stacks->stack_a, chunk_max_nums,
																	chunk_i);
		a_target_num = get_num_of_target_index(stacks->stack_a,
				get_nearest_target_index(stacks->stack_a, chunk_max_nums, chunk_i));
		b_rotation_info = get_rotation_type_and_num_b(stacks->stack_b, a_target_num);
		// rotate_based_on_info(stack_a, stack_b, a_rotation_info,
		// 													b_rotation_info);
		rotate_based_on_info(stacks, a_rotation_info,
															b_rotation_info);
		exec_and_put_operation(stacks, push_designated, STACK_B);
		SAFE_FREE(a_rotation_info);
		SAFE_FREE(b_rotation_info);
	}
	bring_largest_num_to_top(stacks, STACK_B);
}
