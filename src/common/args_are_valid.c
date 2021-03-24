/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:51 by monoue            #+#    #+#             */
/*   Updated: 2021/03/24 09:15:18 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include "debug.h"

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
		{
			DI(array[index]);
			return (false);
		}
		index++;
	}
	return (true);
}

bool		args_are_valid(size_t args_num, char *args[])
{
	return (args_are_integers(args_num, args)
			&& args_are_unique(args_num, args));
}
