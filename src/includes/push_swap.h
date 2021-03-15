#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# define INT_MAX_DIGITS	10

typedef struct	s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

bool			args_are_valid(size_t argc, char *argv[]);
bool			args_are_unique(size_t argc, char *argv[]);

#endif