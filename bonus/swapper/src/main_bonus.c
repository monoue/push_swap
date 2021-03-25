/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:41:40 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"

static int	main2(size_t args_num, char *args[])
{
	t_stacks	*stacks;
	int			sorted_array[args_num];

	if (args_num > ARGS_LIMIT)
	{
		ft_putendl_err(ARG_NUM_ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	if (!args_are_valid(args_num, args))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	if (args_num < 2)
		return (EXIT_SUCCESS);
	stacks = init_stacks();
	stacks->stack_a = get_struct_list(args_num, args);
	get_sorted_array(sorted_array, args_num, args);
	// exec(&stacks->stack_a, args_num, sorted_array);
	exec(stacks, args_num, sorted_array);
	stacks_del(stacks);
	return (EXIT_SUCCESS);
}

int			main(int argc, char *argv[])
{
	size_t	args_num;
	char	**args;
	int		ret;

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
	ret = main2(args_num, args);
	if (argc == 2)
		ft_free_split(args);
	return (ret);
}
