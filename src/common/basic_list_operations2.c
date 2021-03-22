/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:26:56 by monoue            #+#    #+#             */
/*   Updated: 2021/03/22 16:40:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "debug.h"

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
