#include "push_swap.h"
#include "debug.h"
#include "swapper.h"

bool	is_sorted(t_num *stack)
{
	t_num	*tmp_stack;
	int		tmp_num;

	tmp_num = stack->num;
	tmp_stack = stack->next;
	while (tmp_stack)
	{
		if (tmp_stack->num < tmp_num)
			return (false);
		tmp_num = tmp_stack->num;
		tmp_stack = tmp_stack->next;
	}
	return (true);
}
