/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tab_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:05:52 by monoue            #+#    #+#             */
/*   Updated: 2021/03/26 16:48:54 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"
#include "debug_bonus.h"
#include "swapper_bonus.h"

void	put_tab(int n)
{
	const int	intlen = ft_intlen(n);
	const int	tabsize = 8;
	const int	to_fill_len = tabsize - intlen;
	int			index;

	index = 0;
	while (index < to_fill_len)
	{
		ft_putchar_err(' ');
		index++;
	}
}
