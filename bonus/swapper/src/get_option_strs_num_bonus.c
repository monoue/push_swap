/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option_strs_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:48:57 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 17:44:05 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "swapper_bonus.h"

static bool	is_option_char(char c)
{
	const char	*option_chars = "fontc";

	return (ft_strchr(option_chars, c));
}

static bool	is_option_str(const char *str)
{
	const size_t	len = ft_strlen(str);
	const char		option_indicator = '-';
	size_t			index;

	if (len < 2 || str[0] != option_indicator)
		return (false);
	index = 1;
	while (index < len)
	{
		if (!is_option_char(str[index]))
			return (false);
		index++;
	}
	return (true);
}

size_t		get_option_strs_num(size_t args_num, char *args[])
{
	size_t	index;

	index = 0;
	while (index < args_num && is_option_str(args[index]))
		index++;
	return (index);
}
