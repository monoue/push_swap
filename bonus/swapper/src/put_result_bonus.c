/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 10:47:01 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"

static void	put_num_of_operation(const char *operation, size_t count)
{
	const size_t	len = ft_strlen(operation);

	ft_putstr_err(operation);
	ft_putstr_err(": ");
	if (len == 2)
		ft_putchar_err(' ');
	ft_putnbr_err((int)count);
	ft_putchar_err(('\n'));
}

static void	put_num_of_operations(t_stacks *stacks)
{
	ft_putchar_err(('\n'));
	ft_putendl_err(">>>> operation count <<<<");
	put_num_of_operation("sa", stacks->counts->sa_count);
	put_num_of_operation("sb", stacks->counts->sb_count);
	put_num_of_operation("ss", stacks->counts->ss_count);
	put_num_of_operation("pa", stacks->counts->pa_count);
	put_num_of_operation("pb", stacks->counts->pb_count);
	put_num_of_operation("ra", stacks->counts->ra_count);
	put_num_of_operation("rb", stacks->counts->rb_count);
	put_num_of_operation("rr", stacks->counts->rr_count);
	put_num_of_operation("rra", stacks->counts->rra_count);
	put_num_of_operation("rrb", stacks->counts->rrb_count);
	put_num_of_operation("rrr", stacks->counts->rrr_count);
}

static void	put_total_count(t_stacks *stacks)
{
	ft_putchar_err('\n');
	ft_putstr_err("total count: ");
	ft_putnbr_err((int)stacks->counts->total_count);
	ft_putchar_err('\n');
}

void		put_result(t_stacks *stacks)
{
	if (stacks->flags->num_of_operations_flag)
		put_num_of_operations(stacks);
	if (stacks->flags->total_count_flag)
		put_total_count(stacks);
}
