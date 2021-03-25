/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_three_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:36 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 16:03:56 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"
#include "operation_bonus.h"

// static void	exec_three_pattern(t_num **stack_a, const int pattern)
static void	exec_three_pattern(t_stacks *stacks, const int pattern)
{
	if (pattern == SORTED)
		return ;
	if (pattern == SA_RA)
	{
		exec_and_put_operation(stacks, swap_designated, STACK_A);
		exec_and_put_operation(stacks, rotate_designated, STACK_A);
	}
	else if (pattern == SA)
		exec_and_put_operation(stacks, swap_designated, STACK_A);
	else if (pattern == RRA)
		exec_and_put_operation(stacks, reverse_rotate_designated,
																	STACK_A);
	else if (pattern == RA)
		exec_and_put_operation(stacks, rotate_designated, STACK_A);
	else if (pattern == SA_RRA)
	{
		exec_and_put_operation(stacks, swap_designated, STACK_A);
		exec_and_put_operation(stacks, reverse_rotate_designated,
																	STACK_A);
	}
}

static int	get_pattern2(const int first, const int second, const int third)
{
	const t_pattern_set	sets[] = {
		{(first < second && second < third), SORTED},
		{(first < third && third < second), SA_RA},
		{(second < first && first < third), SA},
		{(third < first && first < second), RRA},
		{(second < third && third < first), RA},
		{(third < second && second < first), SA_RRA},
		{false, PATTERNS_NUM}
	};
	t_pattern_set		set;
	int					index;

	index = 0;
	while (index < PATTERNS_NUM)
	{
		set = sets[index];
		if (set.pattern_bool)
			return (set.pattern_num);
		index++;
	}
	return (ERROR);
}

static int	get_pattern(t_num *stack_a)
{
	const int	first = stack_a->num;
	const int	second = stack_a->next->num;
	const int	third = stack_a->next->next->num;

	return (get_pattern2(first, second, third));
}

// void		exec_three(t_num **stack_a)
void		exec_three(t_stacks *stacks)
{
	const int	pattern = get_pattern(stacks->stack_a);

	exec_three_pattern(stacks, pattern);
}
