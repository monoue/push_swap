/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fore_or_back_target_index.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 08:51:31 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

static bool	is_within_range(int num, int chunk_max_nums[], size_t chunk_i)
{
	const int	current_chunk_max = chunk_max_nums[chunk_i];
	int			prev_chunk_max;

	if (chunk_i == 0)
		return (num <= current_chunk_max);
	prev_chunk_max = chunk_max_nums[chunk_i - 1];
	return (num > prev_chunk_max && num <= current_chunk_max);
}

size_t		get_fore_target_index(t_num *stack_a, int chunk_max_nums[],
																size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = stack_a;
	index = 0;
	while (tmp)
	{
		if (is_within_range(tmp->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

size_t		get_back_target_index(t_num *stack_a, int chunk_max_nums[],
																size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = lstlast(stack_a);
	index = 1;
	while (tmp)
	{
		if (is_within_range(tmp->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->prev;
	}
	return (0);
}
