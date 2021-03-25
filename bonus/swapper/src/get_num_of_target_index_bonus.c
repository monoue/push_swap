/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_target_index_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:40:03 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:20:11 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

int	get_num_of_target_index(t_num *stack, size_t target_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = stack;
	index = 0;
	while (index < target_i)
	{
		tmp = tmp->next;
		index++;
	}
	return (tmp->num);
}
