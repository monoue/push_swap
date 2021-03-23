/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:54:01 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 09:52:27 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "libft.h"
#include "defs.h"
#include "operation.h"

int	g_count = 0;

static void	put_count(void)
{
	ft_putstr_err("operation count: ");
	ft_putnbr_err(g_count);
	ft_putchar_err('\n');
}

void		exec(t_num **stack_a, size_t nums_num, int sorted_array[])
{
	print_current_status(*stack_a, NULL);
	if (is_sorted(*stack_a))
		;
	else if (nums_num == 2)
		exec_two(*stack_a);
	else if (nums_num == 3)
		exec_three(stack_a);
	else if (nums_num < 6)
		exec_four_or_five(stack_a);
	(void)sorted_array;
	// else
	// 	exec_one_hundred_or_less(stack_a, nums_num, sorted_array);
	put_count();
}
