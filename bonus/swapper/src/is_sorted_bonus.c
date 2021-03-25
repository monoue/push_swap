/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:12 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:19:33 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"

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
