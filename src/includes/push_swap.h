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

t_num	*lstlast(t_num *lst);
void	lstadd_back(t_num **lst, t_num *new);
t_num	*lstnew(int num);
size_t	lstsize(t_num *num_list);
void	lstdel_front(t_num **lst);
void	lstdel_back(t_num **lst);
void	lstadd_front(t_num **lst, t_num *new);
// void	swap(t_num **num_list);
// void	rotate(t_num **num_list);
// void	reverse_rotate(t_num **num_list);
// void	push(t_num **src, t_num **dst);
void	exec_operation(const char *operation, t_num **list_a, t_num **list_b);

void		swap_a(t_num **list_a, t_num **list_b);
void		swap_b(t_num **list_a, t_num **list_b);
void		swap_double(t_num **list_a, t_num **list_b);

void		rotate_a(t_num **list_a, t_num **list_b);
void		rotate_b(t_num **list_a, t_num **list_b);
void		rotate_double(t_num **list_a, t_num **list_b);

void		reverse_rotate_a(t_num **list_a, t_num **list_b);
void		reverse_rotate_b(t_num **list_a, t_num **list_b);
void		reverse_rotate_double(t_num **list_a, t_num **list_b);

void		push_a(t_num **list_a, t_num **list_b);
void		push_b(t_num **list_a, t_num **list_b);


#endif