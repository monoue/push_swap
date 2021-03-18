#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "operation.h"


void	exec(t_num **stack_a, size_t nums_num)
{
	if (is_sorted(*stack_a))
		;
	else if (nums_num == 2)
		exec_two(*stack_a);
	else if (nums_num == 3)
		exec_three(stack_a);
	else if (nums_num < 6)
		exec_four_or_five(stack_a)
}
