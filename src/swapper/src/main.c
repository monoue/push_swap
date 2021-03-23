/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:39:21 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "swapper.h"

static int	main2(size_t args_num, char *args[])
{
	t_num	*stack_a;
	int		sorted_array[args_num];

	if (!args_are_valid(args_num, args))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	if (args_num < 2)
		return (EXIT_SUCCESS);
	stack_a = get_struct_list(args_num, args);
	get_sorted_array(sorted_array, args_num, args);
	exec(&stack_a, args_num, sorted_array);
	lstdel(stack_a);
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
