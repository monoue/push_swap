/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:11:03 by monoue            #+#    #+#             */
/*   Updated: 2021/02/18 11:50:57 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const size_t	h_len = ft_strlen(haystack);
	const size_t	n_len = ft_strlen(needle);
	size_t			index;

	if (!haystack || n_len > h_len)
		return (NULL);
	if (!needle)
		return ((char *)haystack);
	index = 0;
	while (index < h_len - n_len + 1)
	{
		if (ft_strnequal(&haystack[index], needle, n_len))
			return ((char *)&haystack[index]);
		index++;
	}
	return (NULL);
}
