/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation_type_and_num_b.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:49:30 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 09:22:41 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

static t_rotation_info	*get_rotation_type_and_num_b2(size_t nums_num, size_t target_i)
{
	t_rotation_info	*rotation_info;
	const size_t	middle_i = nums_num / 2;

	if (target_i == 0)
		return (get_zero_rotation());
	rotation_info = malloc(sizeof(t_rotation_info));
	if (!rotation_info)
		exit(EXIT_FAILURE);
	if (target_i <= middle_i)
	{
		rotation_info->rotation_type = NORMAL;
		rotation_info->num = target_i;
	}
	else
	{
		rotation_info->rotation_type = REVERSE;
		rotation_info->num = nums_num - target_i;
	}
	return (rotation_info);
}

static ssize_t			get_index_of_largest_num_under_designattion(t_num *stack, int designated_num)
{
	int		largest_under_designation;
	int		current_num;
	size_t	index;
	ssize_t	ret_i;
	t_num	*tmp;

	tmp = stack;
	largest_under_designation = INT_MIN;
	ret_i = NOT_FOUND;
	index = 0;
	while (tmp)
	{
		current_num = tmp->num;
		if (current_num >= largest_under_designation
												&& current_num < designated_num)
		{
			ret_i = index;
			largest_under_designation = current_num;
		}
		tmp = tmp->next;
		index++;
	}
	return (ret_i);
}

t_rotation_info			*get_rotation_type_and_num_b(t_num *stack_b, int to_be_accepted)
{
	const size_t	nums_num = lstsize(stack_b);
	ssize_t			target_i;

	if (!stack_b || lstsize(stack_b) < 2)
		return (get_zero_rotation());
	target_i = get_index_of_largest_num_under_designattion(stack_b,
																to_be_accepted);
	if (target_i == NOT_FOUND)
		target_i = get_index_of_largest_num(stack_b);
	return (get_rotation_type_and_num_b2(nums_num, target_i));
}
