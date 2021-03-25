/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:21:30 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:54:09 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

static void	push(t_num **src, t_num **dst)
{
	int		tmp;
	t_num	*new;

	if (!lstsize(*src))
		return ;
	tmp = (*src)->num;
	lstdel_front(src);
	new = lstnew(tmp);
	if (!(*dst))
		*dst = new;
	else
		lstadd_front(dst, new);
}

void		push_a(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
}

void		push_b(t_stacks *stacks)
{
	push(&stacks->stack_a, &stacks->stack_b);
}

void		push_designated(t_stacks *stacks, int stack_type)
{
	if (stack_type == STACK_A)
		push_a(stacks);
	else if (stack_type == STACK_B)
		push_b(stacks);
}
