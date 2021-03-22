/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:23:14 by monoue            #+#    #+#             */
/*   Updated: 2021/03/22 11:01:07 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_err(int n)
{
	if (n == INT_MIN)
	{
		write(STDERR_FILENO, INT_MIN_STR, ft_strlen(INT_MIN_STR));
		return ;
	}
	if (n < 0)
	{
		ft_putchar_err('-');
		ft_putnbr_err(-n);
		return ;
	}
	if (n >= 10)
		ft_putnbr_err(n / 10);
	ft_putchar_err(ITOC(n % 10));
}
