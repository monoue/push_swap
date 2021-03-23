/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_chunk_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 09:24:06 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

static size_t	get_nearer_index(size_t	i1, size_t i2, size_t nums_num)
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
	const size_t	fore_index = get_fore_target_index(stack_a, chunk_max_nums,
																	chunk_i);
	const size_t	back_index = get_back_target_index(stack_a, chunk_max_nums,
																	chunk_i);
	const size_t	nums_num = lstsize(stack_a);

	return (get_nearer_index(fore_index, back_index, nums_num));
}

static void	bring_largest_num_to_top(t_num **stack_a, t_num **stack_b,
																int stack_type)
{
	t_num	*stack;
	size_t	largest_num_i;

	if (stack_type == STACK_A)
		stack = *stack_a;
	else if (stack_type == STACK_B)
		stack = *stack_b;
	else
		stack = NULL;
	largest_num_i = get_index_of_largest_num(stack);
	bring_target_index_to_top(stack_a, stack_b, largest_num_i, stack_type);
}

// 20 個までを全部扱う。
// まず、範囲内で、先頭から一番近いものの index を検索。
// 次に、その index に応じて、A を rotate し、target を top に持ってくる。
// push_b は、される前に、適切に受け入れられるように並び替えなくてはならない。
// その並び替え方は、push される数よりも小さい数の中で、最大のものを、一番上に持ってくるというもの。
// これを、chunk の最後まで、while で回してやる。
// その最後の印は、stack_a が空、もしくは、stack_b の個数を CHUNK_SIZE で割った余りが 0 の時
void		deal_chunk_range(t_num **stack_a, t_num **stack_b,
										int chunk_max_nums[], size_t chunk_i)
{
	bool			first_try;
	t_rotation_info	*a_rotation_info;
	t_rotation_info	*b_rotation_info;
	int				a_target_num;

	first_try = true;
	while (stack_a && lstsize(*stack_a)
							&& (first_try || lstsize(*stack_b) % CHUNK_SIZE))
	{
		first_try = false;
		a_rotation_info = get_rotation_type_and_num_a(*stack_a, chunk_max_nums,
																	chunk_i);
		a_target_num = get_num_of_target_index(*stack_a,
				get_nearest_target_index(*stack_a, chunk_max_nums, chunk_i));
		b_rotation_info = get_rotation_type_and_num_b(*stack_b, a_target_num);
		rotate_based_on_info(stack_a, stack_b, a_rotation_info,
															b_rotation_info);
		exec_and_put_operation(stack_a, stack_b, push_designated, STACK_B);
		SAFE_FREE(a_rotation_info);
		SAFE_FREE(b_rotation_info);
	}
	bring_largest_num_to_top(stack_a, stack_b, STACK_B);
}
