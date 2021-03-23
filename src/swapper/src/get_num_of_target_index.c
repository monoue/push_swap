/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_of_target_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:40:03 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:12:09 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

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
