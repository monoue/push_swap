/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_four_or_five_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 07:02:45 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 17:55:49 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static size_t	get_nearest_i_range_n_smallest_nums(t_num *stack,
																	size_t nth)
{
	const size_t	nums_num = lstsize(stack);
	size_t			n;
	size_t			nearest_index;
	size_t			nth_num_index;

	nearest_index = LONG_MAX;
	n = nth;
	while (n > 0)
	{
		nth_num_index = get_nth_smallest_num_index(stack, n);
		nearest_index = get_nearer_distance(nth_num_index, nearest_index,
																	nums_num);
		n--;
	}
	return (nearest_index);
}

/*
** Moves designated numbers of smallest numbers from stack A to B.
** First, gets the index of the nearest number which is within the designation.
** Next, brings it to the top and pushes it to B.
** Repeats this designated times.
*/

static void		push_b_smallest_nums(t_stacks *stacks,
																	size_t num)
{
	size_t	n;
	size_t	nearest_index;

	n = num;
	while (n > 0)
	{
		nearest_index = get_nearest_i_range_n_smallest_nums(stacks->stack_a, n);
		bring_target_index_to_top(stacks, nearest_index, STACK_A);
		exec_and_put_operation(stacks, push_designated, STACK_B);
		n--;
	}
}

static void		bring_larger_to_top(t_stacks *stacks)
{
	const int	first = stacks->stack_b->num;
	const int	second = stacks->stack_b->next->num;

	if (first > second)
		return ;
	exec_and_put_operation(stacks, swap_designated, STACK_B);
}

void			exec_four_or_five(t_stacks *stacks)
{
	const size_t	nums_num = lstsize(stacks->stack_a);
	const size_t	diff_to_three = nums_num - 3;
	size_t			index;
	t_num			*stack_b;

	stack_b = NULL;
	push_b_smallest_nums(stacks, diff_to_three);
	if (diff_to_three > 1)
		bring_larger_to_top(stacks);
	exec_three(stacks);
	index = 0;
	while (index < diff_to_three)
	{
		exec_and_put_operation(stacks, push_designated, STACK_A);
		index++;
	}
}
