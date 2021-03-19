#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "libft.h"
#include "defs.h"
#include "operation.h"

int	g_count = 0;

static void	put_count(int count)
{
	ft_putstr("operation count: ");
	ft_putnbr(count);
	ft_putendl("");
}

void	exec(t_num **stack_a, size_t nums_num, int sorted_array[])
{
	print_current_status(*stack_a, NULL);
	if (is_sorted(*stack_a))
		;
	// else if (nums_num == 2)
	// 	exec_two(*stack_a);
	// else if (nums_num == 3)
	// 	exec_three(stack_a);
	// else if (nums_num < 6)
	// 	exec_four_or_five(stack_a);
	else if (nums_num < 101)
		exec_one_hundred_or_less(stack_a, nums_num, sorted_array);
	put_count(g_count);
}
