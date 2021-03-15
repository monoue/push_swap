#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# define OPERATORS_NUM 11
# define INT_MAX_DIGITS	10

# define ERROR_MESSAGE "Error"
# define SUCCESS_MESSAGE "OK"
# define FAILURE_MESSAGE "KO"

typedef struct	s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

typedef struct	s_op_func_set
{
	char	*str;
	void	(*func)(t_num **, t_num **);
}				t_op_func_set;

bool			args_are_valid(size_t argc, char *argv[]);
bool			args_are_unique(size_t argc, char *argv[]);
t_num			*get_struct_list(size_t args_num, char **num_strs);
bool			is_valid_operator(char *str);

t_num	*lstlast(t_num *stack);
void	lstadd_back(t_num **stack, t_num *new);
t_num	*lstnew(int num);
size_t	lstsize(t_num *stack);
void	lstdel_front(t_num **stack);
void	lstdel_back(t_num **stack);
void	lstadd_front(t_num **stack, t_num *new);

void	exec_operation(const char *operation, t_num **stack_a, t_num **stack_b);

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