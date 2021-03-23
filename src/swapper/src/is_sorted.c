/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:12 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 06:51:13 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"

bool	is_sorted(t_num *stack)
{
	t_num	*tmp_stack;
	int		tmp_num;

	tmp_num = stack->num;
	tmp_stack = stack->next;
	while (tmp_stack)
	{
		if (tmp_stack->num < tmp_num)
			return (false);
		tmp_num = tmp_stack->num;
		tmp_stack = tmp_stack->next;
	}
	return (true);
}
