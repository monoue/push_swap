/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:23:46 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:11:15 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void		reverse_rotate_a(t_num **stack_a, t_num **stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
}

void		reverse_rotate_b(t_num **stack_a, t_num **stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
}

void		reverse_rotate_double(t_num **stack_a, t_num **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void		reverse_rotate_designated(t_num **stack_a, t_num **stack_b,
																int stack_type)
{
	if (stack_type == STACK_A)
		reverse_rotate_a(stack_a, stack_b);
	else if (stack_type == STACK_B)
		reverse_rotate_b(stack_a, stack_b);
	else if (stack_type == DOUBLE)
		reverse_rotate_double(stack_a, stack_b);
}
