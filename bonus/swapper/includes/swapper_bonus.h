/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper_bonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:56:23 by monoue            #+#    #+#             */
/*   Updated: 2021/03/24 09:10:18 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPPER_H
# define SWAPPER_H

typedef struct	s_pattern_set
{
	bool	pattern_bool;
	int		pattern_num;
}				t_pattern_set;

typedef enum	e_rotation_type
{
	NORMAL,
	REVERSE,
	NOTHING,

	ROTATION_TYPE_NUM
}				t_rotation_type;

typedef struct	s_rotation_info {
	int		rotation_type;
	size_t	num;
}				t_rotation_info;

typedef enum	e_pattern
{
	SORTED,
	SA_RA,
	SA,
	RRA,
	RA,
	SA_RRA,

	PATTERNS_NUM
}				t_pattern;

bool			args_are_integers(size_t argc, char *argv[]);
void			bring_target_index_to_top(t_stacks *stacks,
										size_t target_index, int stack_type);
void			deal_chunk_range(t_stacks *stacks,
										int chunk_max_nums[], size_t chunk_i);
void			exec(t_stacks *stacks, size_t nums_num, int sorted_array[]);
bool			is_sorted(t_num *stack);
void			exec_two(t_stacks *stacks);
void			exec_three(t_stacks *stacks);
void			exec_four_or_five(t_stacks *stacks);
void			exec_and_put_operation(t_stacks *stacks,
												t_op_func func, int stack_type);
void			exec2(t_stacks *stacks, size_t nums_num,
															int sorted_array[]);
size_t			get_back_target_index(t_num *stack_a, int chunk_max_nums[],
																size_t chunk_i);
size_t			get_chunk_size(size_t nums_num);
size_t			get_fore_target_index(t_num *stack_a, int chunk_max_nums[],
																size_t chunk_i);
size_t			get_index_of_largest_num(t_num *stack);
int				get_num_of_target_index(t_num *stack, size_t target_i);
size_t			get_nth_smallest_num_index(t_num *stack, size_t n);
t_rotation_info *get_rotation_type_and_num_a(t_num *stack_a,
										int chunk_max_nums[], size_t chunk_i);
t_rotation_info *get_rotation_type_and_num_b(t_num *stack_b,
															int to_be_accepted);
t_rotation_info *get_zero_rotation(void);
size_t			get_nearer_distance(size_t	i1, size_t i2, size_t nums_num);
size_t			get_nearness(size_t index, size_t nums_num);
void			push_designated(t_stacks *stacks,
																int stack_type);
void			rotate_based_on_info(t_stacks *stacks,
							t_rotation_info *a_info, t_rotation_info *b_info);
void			rotate_designated(t_stacks *stacks,
																int stack_type);
void			reverse_rotate_designated(t_stacks *stacks,
																int stack_type);
void			swap_designated(t_stacks *stacks,
																int stack_type);

#endif
