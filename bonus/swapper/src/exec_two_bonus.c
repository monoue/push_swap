/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_two_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:39:14 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:44:29 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"
#include "operation_bonus.h"

// void	exec_two(t_num *stack_a)
void	exec_two(t_stacks *stacks)
{
	const int	first = stacks->stack_a->num;
	const int	second = stacks->stack_a->next->num;

	if (first < second)
		return ;
	exec_and_put_operation(stacks, swap_designated, STACK_A);
}
