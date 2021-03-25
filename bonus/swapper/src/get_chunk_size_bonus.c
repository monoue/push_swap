/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_size_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:21:30 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

size_t	get_chunk_size(size_t nums_num)
{
	if (nums_num < 101)
		return (20);
	if (nums_num < 201)
		return (30);
	if (nums_num < 301)
		return (35);
	if (nums_num < 401)
		return (40);
	if (nums_num < 501)
		return (46);
	return (50);
}
