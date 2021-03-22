/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:23:54 by monoue            #+#    #+#             */
/*   Updated: 2021/03/22 16:23:55 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "debug.h"

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

void		swap_a(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	swap(stack_a);
	ft_putendl("sa");
}

void		swap_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	swap(stack_b);
	ft_putendl("sb");
}

void		swap_double(t_num **stack_a, t_num **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl("ss");
}

void		swap_designated(t_num **stack_a, t_num **stack_b, int stack_type)
{
	if (stack_type == STACK_A)
		swap_a(stack_a, stack_b);
	else if (stack_type == STACK_B)
		swap_b(stack_a, stack_b);
	else if (stack_type == DOUBLE)
		swap_double(stack_a, stack_b);
}
