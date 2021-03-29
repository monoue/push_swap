/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:05:52 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 09:42:00 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"

static void		put_num_counts_of_stacks(t_stacks *stacks)
{
	ft_putstr_err("       a: ");
	ft_putnbr_err((int)lstsize(stacks->stack_a));
	ft_putstr_err("    b: ");
	ft_putnbr_err((int)lstsize(stacks->stack_b));
	ft_putendl_err("\n");
}

static void		put_stacks(t_stacks *stacks, const size_t end_index)
{
	t_num			*stack_a;
	t_num			*stack_b;
	size_t			index;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	index = 0;
	while (index < end_index)
	{
		if (stack_a)
		{
			put_stack_num(stack_a, stacks, STACK_A, index);
			stack_a = stack_a->next;
		}
		else
			ft_putstr_err("        ");
		if (stack_b)
		{
			put_stack_num(stack_b, stacks, STACK_B, index);
			stack_b = stack_b->next;
		}
		ft_putchar_err('\n');
		index++;
	}
	ft_putendl_err("----------------------------------------");
}

static size_t	get_end_index(t_stacks *stacks)
{
	size_t	a_num;
	size_t	b_num;

	a_num = lstsize(stacks->stack_a);
	b_num = lstsize(stacks->stack_b);
	return (ft_max_size_t(a_num, b_num));
}

void			put_status(t_stacks *stacks)
{
	size_t	end_index;
	t_flags	*flags;

	flags = stacks->flags;
	if (flags->nums_in_stacks_flag)
		put_num_counts_of_stacks(stacks);
	if (flags->frame_flag)
	{
		end_index = get_end_index(stacks);
		put_stacks(stacks, end_index);
	}
}
