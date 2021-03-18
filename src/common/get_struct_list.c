#include <push_swap.h>
#include <libft.h>
#include <debug.h>

t_num	*get_struct_list(size_t args_num, char **num_strs)
{
	size_t	index;
	t_num	*num_list;

	num_list = lstnew(ft_atoi(num_strs[0]));
	index = 1;
	while (index < args_num)
	{
		lstadd_back(&num_list, lstnew(ft_atoi(num_strs[index])));
		index++;
	}
	return (num_list);
}
