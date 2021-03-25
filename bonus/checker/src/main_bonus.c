/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:45:01 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:17:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "checker_bonus.h"
#include "libft.h"
#include "debug_bonus.h"

__attribute__((destructor))
void	end()
{
	system("leaks checker");
}


static int	exec(size_t args_num, char *args[])
{
	t_stacks	*stacks;

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
	stacks = init_stacks();
	stacks->stack_a = get_struct_list(args_num, args);
	stacks->stack_b = NULL;
	read_and_exec_operations(stacks);
	put_result(stacks->stack_a, (lstsize(stacks->stack_b) == 0), args_num, args);
	stacks_del(stacks);
	return (EXIT_SUCCESS);
}

int			main(int argc, char *argv[])
{
	int		ret;
	size_t	args_num;
	char	**args;

	if (argc < 2 || str_is_of_tabs_or_spaces(argv[1]))
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
