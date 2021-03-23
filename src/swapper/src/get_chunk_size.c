/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:51:22 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:11:54 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

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
