/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted_array_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:43:18 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:23:36 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

static void	get_int_array(int *array, size_t num, char **strs)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		array[index] = ft_atoi(strs[index]);
		index++;
	}
}

void		get_sorted_array(int *array, size_t num, char **strs)
{
	get_int_array(array, num, strs);
	quick_sort(array, 0, num - 1, num);
}
