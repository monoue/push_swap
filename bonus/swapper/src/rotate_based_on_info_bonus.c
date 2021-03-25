/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_based_on_info_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 16:20:11 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

static int	get_double_rotation_type(int a_type, int b_type)
{
	if (a_type == NOTHING || b_type == NOTHING)
		return (NOTHING);
	if (a_type == NORMAL && b_type == NORMAL)
		return (NORMAL);
	if (a_type == REVERSE && b_type == REVERSE)
		return (REVERSE);
	return (NOTHING);
}

// static void	rotate_designated_based_on_types(t_num **stack_a, t_num **stack_b,
static void	rotate_designated_based_on_types(t_stacks *stacks,
											int rotation_type, int stack_type)
{
	if (rotation_type == NORMAL)
		exec_and_put_operation(stacks, rotate_designated, stack_type);
	else
	{
		exec_and_put_operation(stacks, reverse_rotate_designated,
																	stack_type);
	}
}

// static void	rotate_single_based_on_info(t_num **stack_a, t_num **stack_b,
static void	rotate_single_based_on_info(t_stacks *stacks,
										t_rotation_info *info, int stack_type)
{
	while (info->num > 0)
	{
		// rotate_designated_based_on_types(stack_a, stack_b, info->rotation_type,
		rotate_designated_based_on_types(stacks, info->rotation_type,
																	stack_type);
		info->num--;
	}
}

// static void	rotate_double_based_on_info(t_num **stack_a, t_num **stack_b,
static void	rotate_double_based_on_info(t_stacks *stacks,
							t_rotation_info *a_info, t_rotation_info *b_info)
{
	int	double_rotation_type;

	double_rotation_type = get_double_rotation_type(a_info->rotation_type,
														b_info->rotation_type);
	if (!(double_rotation_type == NORMAL || double_rotation_type == REVERSE))
		return ;
	while (a_info->num > 0 && b_info->num > 0)
	{
		// rotate_designated_based_on_types(stack_a, stack_b,
		rotate_designated_based_on_types(stacks,
											double_rotation_type, DOUBLE);
		a_info->num--;
		b_info->num--;
	}
}

// void		rotate_based_on_info(t_num **stack_a, t_num **stack_b,
void		rotate_based_on_info(t_stacks *stacks,
							t_rotation_info *a_info, t_rotation_info *b_info)
{
	// rotate_double_based_on_info(stack_a, stack_b, a_info, b_info);
	// rotate_single_based_on_info(stack_a, stack_b, a_info, STACK_A);
	// rotate_single_based_on_info(stack_a, stack_b, b_info, STACK_B);
	rotate_double_based_on_info(stacks, a_info, b_info);
	rotate_single_based_on_info(stacks, a_info, STACK_A);
	rotate_single_based_on_info(stacks, b_info, STACK_B);
}
