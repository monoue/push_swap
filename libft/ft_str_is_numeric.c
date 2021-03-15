/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:27:33 by monoue            #+#    #+#             */
/*   Updated: 2021/03/04 15:37:12 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_is_numeric(const char *str)
{
	size_t	index;

	if (!str || str[0] == '\0')
		return (false);
	index = 0;
	while (str[index] != '\0' && ft_isdigit(str[index]))
		index++;
	return (index == ft_strlen(str));
}
