/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:26:56 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 09:20:00 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	lstdel_one(t_num *lst)
{
	lst->prev = NULL;
	lst->next = NULL;
	SAFE_FREE(lst);
}

void	lstdel_front(t_num **stack)
{
	t_num	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	lstdel_one(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}

void	lstdel_back(t_num **stack)
{
	t_num	*head;
	t_num	*tmp;

	if (!stack)
		return ;
	head = *stack;
	tmp = lstlast(*stack);
	*stack = tmp->prev;
	lstdel_one(tmp);
	if (*stack)
		(*stack)->next = NULL;
	*stack = head;
}

void	lstdel(t_num *stack)
{
	t_num	*tmp;

	while (stack)
	{
		tmp = stack->next;
		lstdel_one(stack);
		stack = tmp;
	}
}

void	stacks_del(t_stacks *stacks)
{
	lstdel(stacks->stack_a);
	lstdel(stacks->stack_b);
	SAFE_FREE(stacks);
}
