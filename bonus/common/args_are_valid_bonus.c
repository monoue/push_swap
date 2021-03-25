/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_valid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:51 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:18:40 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

#include "debug_bonus.h"

static bool	args_are_unique(size_t args_num, char **args)
{
	int		array[args_num];
	size_t	index;

	if (args_num < 2)
		return (true);
	get_sorted_array(array, args_num, args);
	index = 0;
	while (index < args_num - 1)
	{
		if (array[index] == array[index + 1])
			return (false);
		index++;
	}
	return (true);
}

bool		args_are_valid(size_t args_num, char *args[])
{
	return (args_are_integers(args_num, args)
			&& args_are_unique(args_num, args));
}
