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

// t_num	*lst_index(t_num *num_list, size_t index)
// {
// 	size_t	i;
// 	t_num	*tmp;

// 	tmp = num_list;
// 	i = 0;
// 	while (i < index)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (tmp);
// }

static void	exec_operation(const char *operation, t_num **stack_a, t_num **stack_b)
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
			set.func(stack_a, stack_b);
			print_current_status(*stack_a, *stack_b);
			return ;
		}
		index++;
	}
}

void	read_and_exec_operations(t_num **stack_a, t_num **stack_b)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &line)) >= 0)
	{
		if (ret == 0)
		{
			SAFE_FREE(line);
			break ;
		}
		if (!is_valid_operator(line))
		{
			SAFE_FREE(line);
			ft_putendl_err("Error");
			exit(EXIT_SUCCESS);
		}
		exec_operation(line, stack_a, stack_b);
		SAFE_FREE(line);
	}
}
