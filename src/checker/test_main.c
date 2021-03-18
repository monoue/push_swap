#include "push_swap.h"
#include "libft.h"
#include "debug.h"

int main(int argc, char *argv[])
{
	if (argc <= 1)
		return (EXIT_SUCCESS);
	t_num	*stack_a;
	t_num	*stack_b;

	stack_a = get_struct_list((size_t)argc - 1, &argv[1]);
	stack_b = NULL;

	print_current_status(stack_a, stack_b);
	exec_operation("sa", &stack_a, &stack_b);
	exec_operation("pb", &stack_a, &stack_b);
	exec_operation("pb", &stack_a, &stack_b);
	exec_operation("sb", &stack_a, &stack_b);
	// put_result(stack_a, get_struct_list((size_t)argc - 1, &argv[1]), stack_b);
	put_result(stack_a, (lstsize(stack_b) == 0), (size_t)argc - 1, &argv[1]);
}
