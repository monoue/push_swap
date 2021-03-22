#ifndef SWAPPER_H
# define SWAPPER_H

# define CHUNK_SIZE 20

int	g_count;

typedef struct	s_pattern_set
{
	bool	pattern_bool;
	int		pattern_num;
}				t_pattern_set;

typedef enum	e_rotation_type
{
	NORMAL,
	REVERSE,
	BOTH,
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

typedef enum	e_stacks
{
	STACK_A,
	STACK_B,
	DOUBLE,

	STACKS_NUM
}				t_stacks;

typedef void	(*op_func)(t_num **, t_num **, int);

void	bring_target_index_to_top(t_num **stack_a, t_num **stack_b, size_t target_index, int stack_type);
void	exec(t_num **stack_a, size_t nums_num, int sorted_array[]);
bool	is_sorted(t_num *stack);
void	exec_two(t_num *stack_a);
void	exec_three(t_num **stack_a);
void	exec_four_or_five(t_num **stack_a);
void	exec_and_put_operation(t_num **stack_a, t_num **stack_b, void(*func)(t_num **, t_num **, int), int stack_type);
int		get_num_of_target_index(t_num *stack, size_t target_i);
t_rotation_info	*get_rotation_type_and_num(size_t nums_num, size_t target_i);
t_rotation_info *get_rotation_type_and_num_a2(size_t fore_index, size_t back_index);
t_rotation_info *get_zero_rotation(void);
size_t	get_nearer_index(size_t	i1, size_t i2, size_t nums_num);
size_t	get_nearness(size_t index, size_t nums_num);
void		push_designated(t_num **stack_a, t_num **stack_b, int stack_type);
void		swap_designated(t_num **stack_a, t_num **stack_b, int stack_type);
void		rotate_designated(t_num **stack_a, t_num **stack_b, int stack_type);
void		reverse_rotate_designated(t_num **stack_a, t_num **stack_b, int stack_type);
void	exec_one_hundred_or_less(t_num **stack_a, size_t nums_num, int sorted_array[]);

#endif