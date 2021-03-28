/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_num_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:05:52 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 17:50:32 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "libft.h"
#include "debug_bonus.h"

static bool	is_type_b(int op_type)
{
	const int	b_ops_num = 7;
	const int	b_ops[] = {OP_SB, OP_SS, OP_PB, OP_RB, OP_RR, OP_RRB, OP_RRR};
	size_t		index;

	index = 0;
	while (index < b_ops_num)
	{
		if (b_ops[index] == op_type)
			return (true);
		index++;
	}
	return (false);
}

static bool	is_type_a(int op_type)
{
	const int	a_ops[] = {OP_SA, OP_SS, OP_PA, OP_RA, OP_RR, OP_RRA, OP_RRR};
	const int	a_ops_num = 7;
	size_t		index;

	index = 0;
	while (index < a_ops_num)
	{
		if (a_ops[index] == op_type)
			return (true);
		index++;
	}
	return (false);
}

static bool	is_target_type(t_stack_type stack_type, int last_op)
{
	if (stack_type == STACK_A && is_type_a(last_op))
		return (true);
	if (stack_type == STACK_B && is_type_b(last_op))
		return (true);
	return (false);
}

static bool	is_color_target_num(t_stacks *stacks, t_stack_type stack_type,
												size_t index)
{
	const int	last_op = stacks->last_op;
	size_t		stack_size;

	if (!is_target_type(stack_type, stacks->last_op))
		return (false);
	if (stack_type == STACK_A)
		stack_size = lstsize(stacks->stack_a);
	else
		stack_size = lstsize(stacks->stack_b);
	if (last_op == OP_RA || last_op == OP_RB || last_op == OP_RR)
		return (index + 1 == stack_size);
	if (index == 0)
	{
		return (last_op == OP_SA || last_op == OP_SB || last_op == OP_SS
				|| last_op == OP_PA || last_op == OP_PB);
	}
	if (index == 1)
	{
		return (last_op == OP_SA || last_op == OP_SB || last_op == OP_SS
				|| last_op == OP_RRA || last_op == OP_RRB || last_op == OP_RRR);
	}
	return (false);
}

void		put_stack_num(t_num *stack, t_stacks *stacks,
										t_stack_type stack_type, size_t index)
{
	bool	is_color_target;

	is_color_target = is_color_target_num(stacks, stack_type, index);
	put_tab(stack->num);
	if (is_color_target)
		ft_putstr_err(RED_S);
	ft_putnbr_err(stack->num);
	if (is_color_target)
		ft_putstr_err(RESET);
}
