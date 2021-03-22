/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_put_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:55:13 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 08:18:50 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "operation.h"

void	exec_and_put_operation(t_num **stack_a, t_num **stack_b, t_op_func func,
																int stack_type)
{
	func(stack_a, stack_b, stack_type);
	g_count++;
	print_current_status_wrapper(stack_a, stack_b);
}
