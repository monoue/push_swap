/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:33:45 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 06:33:47 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# include "defs.h"

void		swap_a(t_num **stack_a, t_num **stack_b);
void		swap_b(t_num **stack_a, t_num **stack_b);
void		swap_double(t_num **stack_a, t_num **stack_b);

void		rotate_a(t_num **stack_a, t_num **stack_b);
void		rotate_b(t_num **stack_a, t_num **stack_b);
void		rotate_double(t_num **stack_a, t_num **stack_b);

void		reverse_rotate_a(t_num **stack_a, t_num **stack_b);
void		reverse_rotate_b(t_num **stack_a, t_num **stack_b);
void		reverse_rotate_double(t_num **stack_a, t_num **stack_b);

void		push_a(t_num **stack_a, t_num **stack_b);
void		push_b(t_num **stack_a, t_num **stack_b);

#endif
