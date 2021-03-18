#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# include "defs.h"

bool			args_are_valid(size_t argc, char *argv[]);
bool			args_are_unique(size_t argc, char *argv[]);
t_num			*get_struct_list(size_t args_num, char **num_strs);
bool			is_valid_operator(char *str);

void		quick_sort(int array[], int left, int right);
void		get_sorted_array(int *array, size_t num, char **strs);

t_num	*lstlast(t_num *stack);
void	lstadd_back(t_num **stack, t_num *new);
t_num	*lstnew(int num);
size_t	lstsize(t_num *stack);
void	lstdel_front(t_num **stack);
void	lstdel_back(t_num **stack);
void	lstadd_front(t_num **stack, t_num *new);

#endif