/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_list_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:41:59 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:23:34 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

t_num	*get_struct_list(size_t args_num, char **num_strs)
{
	size_t	index;
	t_num	*num_list;

	num_list = lstnew(ft_atoi(num_strs[0]));
	index = 1;
	while (index < args_num)
	{
		lstadd_back(&num_list, lstnew(ft_atoi(num_strs[index])));
		index++;
	}
	return (num_list);
}
