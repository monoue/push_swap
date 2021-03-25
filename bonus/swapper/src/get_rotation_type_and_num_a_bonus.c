/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation_type_and_num_a_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:40:21 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:20:01 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

t_rotation_info	*get_rotation_type_and_num_a2(size_t fore_nearness,
														size_t back_nearness)
{
	t_rotation_info	*rotation_info;

	rotation_info = malloc(sizeof(t_rotation_info));
	if (!rotation_info)
		exit(EXIT_FAILURE);
	if (fore_nearness <= back_nearness)
	{
		rotation_info->rotation_type = NORMAL;
		rotation_info->num = fore_nearness;
	}
	else
	{
		rotation_info->rotation_type = REVERSE;
		rotation_info->num = back_nearness;
	}
	return (rotation_info);
}

t_rotation_info	*get_rotation_type_and_num_a(t_num *stack_a,
										int chunk_max_nums[], size_t chunk_i)
{
	const size_t	nums_num = lstsize(stack_a);
	size_t			fore_index;
	size_t			back_index;
	size_t			back_nearness;

	fore_index = get_fore_target_index(stack_a, chunk_max_nums, chunk_i);
	back_index = get_back_target_index(stack_a, chunk_max_nums, chunk_i);
	back_nearness = get_nearness(back_index, nums_num);
	return (get_rotation_type_and_num_a2(fore_index, back_nearness));
}
