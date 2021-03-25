/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_operator_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:41:08 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:23:29 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

bool	is_valid_operator(char *str)
{
	const char	*operators[OPERATORS_NUM + 1] = {
		"sa", "sb", "ss",
		"pa", "pb",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr",
		NULL
	};
	size_t		index;

	index = 0;
	while (index < OPERATORS_NUM)
	{
		if (ft_strequal(str, operators[index]))
			return (true);
		index++;
	}
	return (false);
}
