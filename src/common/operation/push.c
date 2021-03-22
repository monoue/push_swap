/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:21:30 by monoue            #+#    #+#             */
/*   Updated: 2021/03/22 16:21:44 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "debug.h"

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

void		push_a(t_num **stack_a, t_num **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl("pa");
}

void		push_b(t_num **stack_a, t_num **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl("pb");
}

void		push_designated(t_num **stack_a, t_num **stack_b, int stack_type)
{
	if (stack_type == STACK_A)
		push_a(stack_a, stack_b);
	else if (stack_type == STACK_B)
		push_b(stack_a, stack_b);
}
