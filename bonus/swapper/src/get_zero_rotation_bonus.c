/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zero_rotation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:39:32 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:19:40 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "swapper_bonus.h"
#include "defs_bonus.h"
#include "libft.h"
#include "operation_bonus.h"

t_rotation_info	*get_zero_rotation(void)
{
	t_rotation_info	*rotation_info;

	rotation_info = malloc(sizeof(t_rotation_info));
	if (!rotation_info)
		exit(EXIT_FAILURE);
	rotation_info->rotation_type = NOTHING;
	rotation_info->num = 0;
	return (rotation_info);
}
