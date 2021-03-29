/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_empty_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:27:54 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 10:33:14 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

bool	args_has_empty(size_t args_num, char **args)
{
	size_t	index;

	index = 0;
	while (index < args_num)
	{
		if (str_is_of_tabs_or_spaces(args[index]))
			return (true);
		index++;
	}
	return (false);
}
