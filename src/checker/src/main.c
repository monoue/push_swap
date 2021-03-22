#include "push_swap.h"
#include "checker.h"
#include "libft.h"
#include "debug.h"

// checker
int	main(int argc, char *argv[])
{
	t_num	*stack_a;
	t_num	*stack_b;
	char	**args;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = get_struct_list(ft_count_strs((const char **)args), args);
		stack_b = NULL;
		read_and_exec_operations(&stack_a, &stack_b);
		put_result(stack_a, (lstsize(stack_b) == 0), ft_count_strs((const char **)args), args);
	}
	else
	{
		if (!args_are_valid((size_t)argc, argv))
		{
			ft_putendl_err(ERROR_MESSAGE);
			return (EXIT_SUCCESS);
		}
		stack_a = get_struct_list((size_t)argc - 1, &argv[1]);
		stack_b = NULL;
		read_and_exec_operations(&stack_a, &stack_b);
		put_result(stack_a, (lstsize(stack_b) == 0), argc - 1, &argv[1]);
	}
}
