/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 10:37:24 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"

static void	set_options(t_flags *flags, const char *str)
{
	if (ft_strchr(str, 'f'))
		flags->frame_flag = true;
	if (ft_strchr(str, 'o'))
		flags->num_of_operations_flag = true;
	if (ft_strchr(str, 'n'))
		flags->nums_in_stacks_flag = true;
	if (ft_strchr(str, 't'))
		flags->total_count_flag = true;
	if (ft_strchr(str, 'c'))
		flags->color_flag = true;
}

static void	set_flags(size_t option_strs_num, char *args[], t_flags *flags)
{
	size_t	index;

	*flags = (t_flags){0};
	index = 0;
	while (index < option_strs_num)
	{
		set_options(flags, args[index]);
		index++;
	}
}

static void	parse_and_exec(size_t args_num, char *args[], t_flags *flags)
{
	t_stacks	*stacks;
	int			sorted_array[args_num];

	stacks = init_stacks();
	stacks->flags = flags;
	stacks->stack_a = get_struct_list(args_num, args);
	stacks->stack_b = NULL;
	get_sorted_array(sorted_array, args_num, args);
	exec(stacks, args_num, sorted_array);
	put_result(stacks);
	stacks_del(stacks);
}

static int	main2(size_t args_num, char *args[])
{
	const size_t	option_strs_num = get_option_strs_num(args_num, args);
	const size_t	num_strs_num = args_num - option_strs_num;
	t_flags			*flags;

	if (num_strs_num > ARGS_LIMIT)
	{
		ft_putendl_err(ARG_NUM_ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	if (!args_are_valid(num_strs_num, &args[option_strs_num]))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	if (num_strs_num < 2)
		return (EXIT_SUCCESS);
	flags = malloc(sizeof(t_flags));
	if (!flags)
		exit(EXIT_FAILURE);
	set_flags(option_strs_num, args, flags);
	parse_and_exec(num_strs_num, &args[option_strs_num], flags);
	return (EXIT_SUCCESS);
}

int			main(int argc, char *argv[])
{
	size_t	args_num;
	char	**args;
	int		ret;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (args_has_empty((size_t)argc - 1, &argv[1]))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
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
