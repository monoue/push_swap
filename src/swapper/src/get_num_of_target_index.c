#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

int	get_num_of_target_index(t_num *stack, size_t target_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = stack;
	index = 0;
	while (index < target_i)
	{
		tmp = tmp->next;
		index++;
	}
	return (tmp->num);
}
