/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:26:56 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:10:43 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

size_t	lstsize(t_num *stack)
{
	t_num	*tmp;
	size_t	count;

	if (!stack)
		return (0);
	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_num	*lstlast(t_num *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_num	*lstnew(int num)
{
	t_num	*tmp;

	if (!(tmp = malloc(sizeof(t_num))))
		return (NULL);
	tmp->num = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	lstadd_front(t_num **stack, t_num *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

void	lstadd_back(t_num **stack, t_num *new)
{
	if (!stack || !new)
		return ;
	new->prev = lstlast(*stack);
	lstlast(*stack)->next = new;
}
