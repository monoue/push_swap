/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:23:46 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 15:14:17 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

static void	reverse_rotate(t_num **num_list)
{
	int		tmp;

	if (lstsize(*num_list) < 2)
		return ;
	tmp = lstlast(*num_list)->num;
	lstdel_back(num_list);
	lstadd_front(num_list, lstnew(tmp));
}

void		reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->rra_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RRA;
}

void		reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->rrb_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RRB;
}

void		reverse_rotate_double(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
	if (stacks->flags->num_of_operations_flag)
		stacks->counts->rrr_count++;
	if (stacks->flags->color_flag)
		stacks->last_op = OP_RRR;
}

void		reverse_rotate_designated(t_stacks *stacks,
																int stack_type)
{
	if (stack_type == STACK_A)
		reverse_rotate_a(stacks);
	else if (stack_type == STACK_B)
		reverse_rotate_b(stacks);
	else if (stack_type == DOUBLE)
		reverse_rotate_double(stacks);
}
