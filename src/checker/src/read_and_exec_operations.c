/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:46:45 by monoue            #+#    #+#             */
/*   Updated: 2021/03/24 10:11:46 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "operation.h"

static void	exec_operation(const char *operation, t_num **stack_a,
																t_num **stack_b)
{
	const t_op_func_set	sets[] = {
		{"sa", &swap_a}, {"sb", &swap_b}, {"ss", &swap_double},
		{"pa", &push_a}, {"pb", &push_b},
		{"ra", &rotate_a}, {"rb", &rotate_b}, {"rr", &rotate_double},
		{"rra", &reverse_rotate_a}, {"rrb", &reverse_rotate_b},
		{"rrr", &reverse_rotate_double},
		{NULL, NULL}
	};
	t_op_func_set		set;
	size_t				index;

	index = 0;
	while (sets[index].str)
	{
		set = sets[index];
		if (ft_strequal(set.str, operation))
		{
			set.func(stack_a, stack_b);
			return ;
		}
		index++;
	}
}

void		read_and_exec_operations(t_stacks *stacks)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &line)) >= 0)
	{
		if (ret == 0)
		{
			SAFE_FREE(line);
			break ;
		}
		if (!is_valid_operator(line))
		{
			SAFE_FREE(line);
			ft_putendl_err("Error");
			lstdel(stacks->stack_a);
			lstdel(stacks->stack_b);
			exit(EXIT_FAILURE);
		}
		exec_operation(line, &stacks->stack_a, &stacks->stack_b);
		SAFE_FREE(line);
	}
}
