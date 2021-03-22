/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_hundred_or_less.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 08:14:49 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

void	set_chunk_max_nums(int chunk_max_nums[], size_t chunks_num, int sorted_array[], size_t nums_num)
{
	size_t	src_i;
	size_t	dst_i;

	src_i = 0;
	dst_i = 0;
	size_t	index;

	index = 0;
	while (dst_i < chunks_num - 1)
	{
		chunk_max_nums[dst_i] = sorted_array[CHUNK_SIZE * (dst_i + 1) - 1];
		dst_i++;
	}
	chunk_max_nums[dst_i] = sorted_array[nums_num - 1];
}

size_t	get_chunks_num(size_t nums_num, size_t chunk_size)
{
	return (nums_num / chunk_size + (nums_num % chunk_size > 0));
}

bool	is_within_range(int num, int chunk_max_nums[], size_t chunk_i)
{
	const int	current_chunk_max = chunk_max_nums[chunk_i];
	int			prev_chunk_max;

	if (chunk_i == 0)
		return (num <= current_chunk_max);
	prev_chunk_max = chunk_max_nums[chunk_i - 1];
	return (num > prev_chunk_max && num <= current_chunk_max);
}

size_t	get_fore_target_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = stack_a;
	index = 0;
	while (tmp)
	{
		if (is_within_range(tmp->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

size_t	get_back_target_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = lstlast(stack_a);
	index = 1;
	while (tmp)
	{
		if (is_within_range(tmp->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->prev;
	}
	return (0);
}

size_t	get_nearer_index(size_t	i1, size_t i2, size_t nums_num)
{
	const size_t	nearness1 = get_nearness(i1, nums_num);
	const size_t	nearness2 = get_nearness(i2, nums_num);

	if (nearness1 <= nearness2)
		return (i1);
	else
		return (nums_num - i2);
}

size_t	get_nearest_target_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	const size_t	fore_index = get_fore_target_index(stack_a, chunk_max_nums, chunk_i);
	const size_t	back_index = get_back_target_index(stack_a, chunk_max_nums, chunk_i);
	const size_t	nums_num = lstsize(stack_a);

	return (get_nearer_index(fore_index, back_index, nums_num));
}

t_rotation_info *get_rotation_type_and_num_a(t_num *stack_a,
										int chunk_max_nums[], size_t chunk_i)
{
	const size_t	fore_index = get_fore_target_index(stack_a, chunk_max_nums,
																	chunk_i);
	const size_t	back_index = get_back_target_index(stack_a, chunk_max_nums,
																	chunk_i);
	const size_t	nums_num = lstsize(stack_a);
	const size_t	fore_nearness = fore_index;
	const size_t	back_nearness = get_nearness(back_index, nums_num);

	return (get_rotation_type_and_num_a2(fore_nearness, back_nearness));
}

ssize_t	get_index_of_largest_num_under_designattion(t_num *stack, int designated_num)
{
	int		largest_under_designation;
	int		current_num;
	size_t	index;
	ssize_t	ret_i;
	t_num	*tmp;

	tmp = stack;
	largest_under_designation = INT_MIN;
	ret_i = NOT_FOUND;
	index = 0;
	while (tmp)
	{
		current_num = tmp->num;
		if (current_num >= largest_under_designation && current_num < designated_num)
		{
			ret_i = index;
			largest_under_designation = current_num;
		}
		tmp = tmp->next;
		index++;
	}
	return (ret_i);
}

size_t	get_index_of_largest_num(t_num *stack)
{
	t_num	*tmp;
	size_t	index;
	size_t	ret_i;
	int		largest;
	int		current_num;

	tmp = stack;
	largest = INT_MIN;
	index = 0;
	ret_i = 0;
	while (tmp)
	{
		current_num = tmp->num;
		if (current_num >= largest)
		{
			largest = current_num;
			ret_i = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (ret_i);
}

void	bring_largest_num_to_top(t_num **stack_a, t_num **stack_b, int stack_type)
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

// 元
// この関数も、必要試行回数と種類 (r / rr) を返すようにする。
void	set_b_for_acception(t_num **stack_a, t_num **stack_b)
{
	int		to_be_accepted;
	ssize_t	target_i;

	if (!stack_a || lstsize(*stack_a) == 0 || !stack_b || lstsize(*stack_b) < 2)
		return ;
	to_be_accepted = (*stack_a)->num;
	target_i = get_index_of_largest_num_under_designattion(*stack_b, to_be_accepted);
	if (target_i == NOT_FOUND)
		bring_largest_num_to_top(stack_a, stack_b, STACK_B);
	else
		bring_target_index_to_top(stack_a, stack_b, target_i, STACK_B);
}

// この関数も、必要試行回数と種類 (r / rr) を返すようにする。
t_rotation_info *get_rotation_type_and_num_b(t_num *stack_b, int to_be_accepted)
{
	const size_t	nums_num = lstsize(stack_b);
	ssize_t			target_i;

	if (!stack_b || lstsize(stack_b) < 2)
		return (get_zero_rotation());
	target_i = get_index_of_largest_num_under_designattion(stack_b, to_be_accepted);
	if (target_i == NOT_FOUND)
		target_i = get_index_of_largest_num(stack_b);
	return (get_rotation_type_and_num(nums_num, target_i));
}

// 元
// 20 個までを全部扱う。
// まず、範囲内で、先頭から一番近いものの index を検索。
// 次に、その index に応じて、A を rotate し、target を top に持ってくる。
// push_b は、される前に、適切に受け入れられるように並び替えなくてはならない。
// その並び替え方は、push される数よりも小さい数の中で、最大のものを、一番上に持ってくるというもの。
// これを、chunk の最後まで、while で回してやる。
// その最後の印は、stack_a が空、もしくは、stack_b の個数を CHUNK_SIZE で割った余りが 0 の時
// void	deal_chunk_range(t_num **stack_a, t_num **stack_b, int chunk_max_nums[], size_t chunk_i)
// {
// 	size_t	target_i;
// 	bool	first_try;

// 	first_try = true;
// 	while (stack_a && lstsize(*stack_a) && (first_try || lstsize(*stack_b) % CHUNK_SIZE))
// 	{
// 		first_try = false;
// 		// 同時に回すには、ここで、target_num も取る必要がある。
// 		// 引数が余っているので、参照渡しにできる。
// 		target_i = get_nearest_target_index(*stack_a, chunk_max_nums, chunk_i);

// 		// ここから
// 		bring_target_index_to_top(stack_a, stack_b, target_i, STACK_A);
// 		set_b_for_acception(stack_a, stack_b);
// 		exec_and_put_operation(stack_a, stack_b, push_designated, STACK_B);
// 		// ここまでを回す

// 	}
// 	bring_largest_num_to_top(stack_a, stack_b, STACK_B);
// }

// void	rotate_both_common_times(t_num **stack_a, t_num **stack_b, const int double_rotation_type)
// {
// 	while (a_info->num > 0 && b_info->num > 0)
// 	{
// 		if (double_rotation_type == NORMAL)
// 			rotate_double(stack_a, stack_b);
// 		else
// 			reverse_rotate_double(stack_a, stack_b);
// 		a_info->num--;
// 		b_info->num--;
// 	}
// }

// 20 個までを全部扱う。
// まず、範囲内で、先頭から一番近いものの index を検索。
// 次に、その index に応じて、A を rotate し、target を top に持ってくる。
// push_b は、される前に、適切に受け入れられるように並び替えなくてはならない。
// その並び替え方は、push される数よりも小さい数の中で、最大のものを、一番上に持ってくるというもの。
// これを、chunk の最後まで、while で回してやる。
// その最後の印は、stack_a が空、もしくは、stack_b の個数を CHUNK_SIZE で割った余りが 0 の時
void	deal_chunk_range(t_num **stack_a, t_num **stack_b, int chunk_max_nums[],
																size_t chunk_i)
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
	}
	bring_largest_num_to_top(stack_a, stack_b, STACK_B);
}

void	exec_one_hundred_or_less(t_num **stack_a, size_t nums_num,
															int sorted_array[])
{
	const size_t	chunks_num = get_chunks_num(nums_num, CHUNK_SIZE);
	int				chunk_max_nums[chunks_num];
	t_num			*stack_b;
	size_t			index;

	set_chunk_max_nums(chunk_max_nums, chunks_num, sorted_array, nums_num);
	stack_b = NULL;
	index = 0;
	while (index < chunks_num)
	{
		deal_chunk_range(stack_a, &stack_b, chunk_max_nums, index);
		index++;
	}
	while (lstsize(stack_b))
		exec_and_put_operation(stack_a, &stack_b, push_designated, STACK_A);
}
