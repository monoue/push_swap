/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nth_smallest_num_index_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 07:02:45 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:20:37 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static int		get_smallest_num(t_num *stack)
{
	int		smallest_num;
	t_num	*tmp;

	smallest_num = stack->num;
	tmp = stack->next;
	while (tmp)
	{
		smallest_num = ft_min_int(tmp->num, smallest_num);
		tmp = tmp->next;
	}
	return (smallest_num);
}

static int		get_smallest_num_over_designation(t_num *stack,
															int designated_num)
{
	int		designated_smallest;
	t_num	*tmp;

	tmp = stack;
	designated_smallest = INT_MAX;
	while (tmp)
	{
		if (tmp->num <= designated_smallest && tmp->num > designated_num)
			designated_smallest = tmp->num;
		tmp = tmp->next;
	}
	return (designated_smallest);
}

static int		get_nth_smallest_num(t_num *stack, size_t n)
{
	int		ret;
	size_t	count;

	ret = get_smallest_num(stack);
	count = 1;
	while (count < n)
	{
		ret = get_smallest_num_over_designation(stack, ret);
		count++;
	}
	return (ret);
}

static size_t	get_target_index(t_num *stack, int target)
{
	const size_t	nums_num = lstsize(stack);
	t_num			*tmp;
	size_t			index;

	tmp = stack;
	index = 0;
	while (index < nums_num)
	{
		if (tmp->num == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}

size_t			get_nth_smallest_num_index(t_num *stack, size_t n)
{
	const int	nth_smallest_num = get_nth_smallest_num(stack, n);

	return (get_target_index(stack, nth_smallest_num));
}
