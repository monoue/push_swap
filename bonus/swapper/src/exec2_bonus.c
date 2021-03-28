/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 17:56:39 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static void		set_chunk_max_nums(int chunk_max_nums[], size_t chunks_num,
											int sorted_array[], size_t nums_num)
{
	size_t	chunk_size;
	size_t	dst_i;

	dst_i = 0;
	chunk_size = get_chunk_size(nums_num);
	if (chunks_num > 1)
	{
		while (dst_i < chunks_num - 1)
		{
			chunk_max_nums[dst_i] = sorted_array[chunk_size * (dst_i + 1) - 1];
			dst_i++;
		}
	}
	chunk_max_nums[dst_i] = sorted_array[nums_num - 1];
}

static size_t	get_chunks_num(size_t nums_num)
{
	const size_t	chunk_size = get_chunk_size(nums_num);

	return (nums_num / chunk_size + (nums_num % chunk_size > 0));
}

void			exec2(t_stacks *stacks, size_t nums_num,
															int sorted_array[])
{
	const size_t	chunks_num = get_chunks_num(nums_num);
	int				chunk_max_nums[chunks_num];
	size_t			index;

	set_chunk_max_nums(chunk_max_nums, chunks_num, sorted_array, nums_num);
	index = 0;
	while (index < chunks_num)
	{
		deal_chunk_range(stacks, chunk_max_nums, index);
		index++;
	}
	while (lstsize(stacks->stack_b))
		exec_and_put_operation(stacks, push_designated, STACK_A);
}
