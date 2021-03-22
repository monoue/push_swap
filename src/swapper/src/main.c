/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 06:48:58 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "debug.h"
#include "swapper.h"

// 動く
// int	main(int argc, char *argv[])
// {
// 	t_num	*stack_a;
// 	size_t	nums_num;
// 	int		sorted_array[argc - 1];

// 	if (argc < 2)
// 		return (EXIT_SUCCESS);
// 	if (!args_are_valid((size_t)argc, argv))
// 	{
// 		ft_putendl_err(ERROR_MESSAGE);
// 		return (EXIT_SUCCESS);
// 	}
// 	nums_num = argc - 1;
// 	if (nums_num == 1)
// 		return (EXIT_SUCCESS);
// 	stack_a = get_struct_list(nums_num, &argv[1]);
// 	get_sorted_array(sorted_array, nums_num, &argv[1]);
// 	exec(&stack_a, nums_num, sorted_array);
// }

int	main(int argc, char *argv[])
{
	t_num	*stack_a;
	size_t	nums_num;
	char	**args;

	if (argc < 2)
		return (EXIT_SUCCESS);
	// 修正の必要あり。args_are_valid が、argc == 2 の時は最初の数字を無視してしまっている。
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args_are_valid(ft_count_strs((const char **)args), args))
		{
			ft_putendl_err(ERROR_MESSAGE);
			return (EXIT_SUCCESS);
		}
		nums_num = ft_count_strs((const char **)args);
		if (nums_num == 1)
			return (EXIT_SUCCESS);
		stack_a = get_struct_list(nums_num, args);
		int		sorted_array[nums_num];
		get_sorted_array(sorted_array, nums_num, args);
		exec(&stack_a, nums_num, sorted_array);
	}
	else
	{
		int		sorted_array[argc - 1];
		if (!args_are_valid((size_t)argc, argv))
		{
			ft_putendl_err(ERROR_MESSAGE);
			return (EXIT_SUCCESS);
		}
		nums_num = argc - 1;
		if (nums_num == 1)
			return (EXIT_SUCCESS);
		stack_a = get_struct_list(nums_num, &argv[1]);
		get_sorted_array(sorted_array, nums_num, &argv[1]);
		exec(&stack_a, nums_num, sorted_array);
	}
}