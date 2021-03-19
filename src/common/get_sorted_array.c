#include "push_swap.h"
#include "libft.h"

static void	get_int_array(int *array, size_t num, char **strs)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		array[index] = ft_atoi(strs[index]);
		index++;
	}
}

// void		get_sorted_array(int *array, size_t num, char **strs)
// {
// 	get_int_array(array, num, strs);
// 	quick_sort(array, 0, num - 1);
// }

void		get_sorted_array(int *array, size_t num, char **strs)
{
	get_int_array(array, num, strs);
	quick_sort(array, 0, num - 1, num);
}