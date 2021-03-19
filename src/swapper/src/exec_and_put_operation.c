#include "push_swap.h"
#include "libft.h"
#include "debug.h"
#include "swapper.h"
#include "operation.h"

void	exec_and_put_operation(t_num **stack_a, t_num **stack_b, void(*func)(t_num **, t_num **))
{
	const t_op_func_set	sets[] = {
		{"sa", &swap_a}, {"sb", &swap_b}, {"ss", &swap_double},
		{"pa", &push_a}, {"pb", &push_b},
		{"ra", &rotate_a}, {"rb", &rotate_b}, {"rr", &rotate_double},
		{"rra", &reverse_rotate_a}, {"rrb", &reverse_rotate_b},
		{"rrr", &reverse_rotate_double},
		{NULL, NULL}
	};
	t_op_func_set		set;
	size_t				index;

	index = 0;
	while (sets[index].str)
	{
		set = sets[index];
		if (set.func == func)
		{
			ft_putendl(set.str);
			break ;
		}
		index++;
	}
	func(stack_a, stack_b);
	g_count++;
	print_current_status_wrapper(stack_a, stack_b);
}
