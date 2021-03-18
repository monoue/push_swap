#ifndef SWAPPER_H
# define SWAPPER_H

# define MIN(x, y) (x) <= (y) ? (x) : (y)
typedef struct	s_pattern_set
{
	bool	pattern_bool;
	int		pattern_num;
}				t_pattern_set;

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

void	exec(t_num **stack_a, size_t nums_num);
bool	is_sorted(t_num *stack);
void	exec_two(t_num *stack_a);
void	exec_three(t_num **stack_a);
void	exec_and_put_operation(t_num **stack_a, t_num **stack_b, void(*func)(t_num **, t_num **));

#endif