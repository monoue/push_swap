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