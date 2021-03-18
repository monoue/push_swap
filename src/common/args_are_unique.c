#include "push_swap.h"
#include "libft.h"

bool		args_are_unique(size_t argc, char **argv)
{
	int		array[argc - 1];
	size_t	index;
	size_t	num;

	if (argc <= 1)
		return (false);
	num = argc - 1;
	if (num == 1)
		return (true);
	get_sorted_array(array, num, &argv[1]);
	index = 0;
	while (index < num - 1)
	{
		if (array[index] == array[index + 1])
			return (false);
		index++;
	}
	return (true);
}
