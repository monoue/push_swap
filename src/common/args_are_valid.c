/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:51 by monoue            #+#    #+#             */
/*   Updated: 2021/03/22 16:34:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static bool	args_are_unique(size_t argc, char **argv)
{
	int		array[argc - 1];
	size_t	index;
	size_t	num;

	if (argc <= 1)
		return (false);
	num = argc - 1;
	if (num == 1)
		return (true);
	get_sorted_array(array, num, &argv[1]);
	index = 0;
	while (index < num - 1)
	{
		if (array[index] == array[index + 1])
			return (false);
		index++;
	}
	return (true);
}

bool		args_are_valid(size_t argc, char *argv[])
{
	return (args_are_integers(argc, argv) && args_are_unique(argc, argv));
}
