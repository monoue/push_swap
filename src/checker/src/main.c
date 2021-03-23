/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:45:01 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 12:49:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include "libft.h"
#include "debug.h"

static int	exec(size_t args_num, char *args[])
{
	t_num	*stack_a;
	t_num	*stack_b;

	if (!args_are_valid(args_num, args))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	stack_a = get_struct_list(args_num, args);
	stack_b = NULL;
	read_and_exec_operations(&stack_a, &stack_b);
	put_result(stack_a, (lstsize(stack_b) == 0), args_num, args);
	lstdel(stack_a);
	lstdel(stack_b);
	return (EXIT_SUCCESS);
}

int			main(int argc, char *argv[])
{
	int		ret;
	size_t	args_num;
	char	**args;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		args_num = ft_count_strs((const char **)args);
	}
	else
	{
		args = &argv[1];
		args_num = argc - 1;
	}
	ret = exec(args_num, args);
	if (argc == 2)
		ft_free_split(args);
	return (ret);
}
