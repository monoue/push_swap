/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearness_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:40:21 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:20:50 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

size_t	get_nearness(size_t index, size_t nums_num)
{
	size_t	back_index;

	if (index >= nums_num)
		return (UINT_MAX);
	back_index = nums_num - index;
	return (ft_min_size_t(index, back_index));
}
