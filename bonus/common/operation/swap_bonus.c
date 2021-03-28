/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:23:54 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 15:13:24 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "debug_bonus.h"

static void	swap(t_num **stack)
{
	int	a;
	int	b;

	if (lstsize(*stack) < 2)
		return ;
	a = (*stack)->num;
	b = (*stack)->next->num;
	lstdel_front(stack);
	lstdel_front(stack);
	if (!(*stack))
		*stack = lstnew(a);
	else
		lstadd_front(stack, lstnew(a));
	lstadd_front(stack, lstnew(b));
}

void		swap_a(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->sa_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_SA;
}

void		swap_b(t_stacks *stacks)
{
	swap(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->sb_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_SB;
}

void		swap_double(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->ss_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_SS;
}

void		swap_designated(t_stacks *stacks, int stack_type)
{
	if (stack_type == STACK_A)
		swap_a(stacks);
	else if (stack_type == STACK_B)
		swap_b(stacks);
	else if (stack_type == DOUBLE)
		swap_double(stacks);
}
