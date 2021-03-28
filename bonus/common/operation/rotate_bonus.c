/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:21:59 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 15:13:54 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

static void	rotate(t_num **num_list)
{
	int	tmp;

	if (lstsize(*num_list) < 2)
		return ;
	tmp = (*num_list)->num;
	lstdel_front(num_list);
	lstadd_back(num_list, lstnew(tmp));
}

void		rotate_a(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->ra_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RA;
}

void		rotate_b(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->rb_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RB;
}

void		rotate_double(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->rr_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RR;
}

void		rotate_designated(t_stacks *stacks, int stack_type)
{
	if (stack_type == STACK_A)
		rotate_a(stacks);
	else if (stack_type == STACK_B)
		rotate_b(stacks);
	else if (stack_type == DOUBLE)
		rotate_double(stacks);
}
