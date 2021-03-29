/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:26:56 by monoue            #+#    #+#             */
/*   Updated: 2021/03/29 09:22:24 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;
	t_counts	*counts;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit(EXIT_FAILURE);
	*stacks = (t_stacks){0};
	counts = malloc(sizeof(t_counts));
	if (!counts)
		exit(EXIT_FAILURE);
	*counts = (t_counts){0};
	stacks->counts = counts;
	return (stacks);
}
