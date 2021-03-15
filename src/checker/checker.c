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

bool	is_valid_operator(char *str)
{
	const char	*operators[OPERATORS_NUM + 1] = {
		"sa", "sb", "ss",
		"pa", "pb",
		"ra","rb", "rr",
		"rra", "rrb", "rrr",
		NULL
	};
	size_t		index;

	index = 0;
	while (index < OPERATORS_NUM)
	{
		if (ft_strequal(str, operators[index]))
			return (true);
		index++;
	}
	return (false);
}

t_num	*lst_index(t_num *num_list, size_t index)
{
	size_t	i;
	t_num	*tmp;

	tmp = num_list;
	i = 0;
	while (i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	exec_operation(const char *operation, t_num **list_a, t_num **list_b)
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

	DS(operation);
	index = 0;
	while (sets[index].str)
	{
		set = sets[index];
		if (ft_strequal(set.str, operation))
		{
			ft_putchar('\n');
			set.func(list_a, list_b);
			print_current_status(*list_a, *list_b);
			return ;
		}
		index++;
	}
}
