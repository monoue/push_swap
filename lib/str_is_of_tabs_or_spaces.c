/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_of_tabs_or_spaces.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:24:38 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 16:56:53 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	str_is_of_tabs_or_spaces(char *str)
{
	const size_t	len = ft_strlen(str);
	size_t			index;

	index = 0;
	while (str[index] == ' ' || str[index] == '\t')
		index++;
	return (index == len);
}
