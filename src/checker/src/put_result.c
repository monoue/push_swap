/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:45:28 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 16:46:27 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static bool	is_sorting_success(t_num *stack_a, size_t nums_num, char **num_strs)
{
	const size_t	a_num = lstsize(stack_a);
	t_num			*tmp_a;
	int				array[nums_num];
	size_t			index;

	if (nums_num == 1)
		return (true);
	if (a_num != nums_num)
		return (false);
	get_sorted_array(array, nums_num, num_strs);
	tmp_a = stack_a;
	index = 0;
	while (index < nums_num)
	{
		if (tmp_a->num != array[index])
			return (false);
		tmp_a = tmp_a->next;
		index++;
	}
	return (true);
}

void		put_result(t_num *stack_a, bool stack_b_is_empty, size_t nums_num,
															char **nums_strs)
{
	bool	success;

	if (!stack_b_is_empty)
	{
		ft_putendl_err(FAILURE_MESSAGE);
		return ;
	}
	success = is_sorting_success(stack_a, nums_num, nums_strs);
	if (success)
		ft_putendl(SUCCESS_MESSAGE);
	else
		ft_putendl(FAILURE_MESSAGE);
}
