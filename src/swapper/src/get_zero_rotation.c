/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zero_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:39:32 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:12:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

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
