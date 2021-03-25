/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <monoue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:33:45 by monoue            #+#    #+#             */
/*   Updated: 2021/03/25 15:55:27 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# include "defs_bonus.h"

void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_double(t_stacks *stacks);

void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_double(t_stacks *stacks);

void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_double(t_stacks *stacks);

void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);

#endif
