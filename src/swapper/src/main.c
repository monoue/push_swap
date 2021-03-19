#include "push_swap.h"
#include "libft.h"
#include "debug.h"
#include "swapper.h"

int	main(int argc, char *argv[])
{
	t_num	*stack_a;
	size_t	nums_num;
	int		sorted_array[argc - 1];

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!args_are_valid((size_t)argc, argv))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return (EXIT_SUCCESS);
	}
	nums_num = argc - 1;
	if (nums_num == 1)
		return (EXIT_SUCCESS);
	stack_a = get_struct_list(nums_num, &argv[1]);
	get_sorted_array(sorted_array, nums_num, &argv[1]);
	exec(&stack_a, nums_num, sorted_array);
}
