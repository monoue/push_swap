#include "push_swap.h"
#include "libft.h"
#include "debug.h"

static bool	is_sorting_success(t_num *stack_a, t_num *original)
{
	const size_t	a_num = lstsize(stack_a);
	const size_t	o_num = lstsize(original);
	t_num			*tmp_a;
	t_num			*tmp_o;
	size_t			index;

	if (a_num != o_num)
		return (false);
	tmp_a = stack_a;
	tmp_o = original;
	index = 0;
	while (index < o_num)
	{
		if (tmp_a->num != tmp_o->num)
			return (false);
		tmp_a = tmp_a->next;
		tmp_o = tmp_o->next;
		index++;
	}
	return (true);
}

void	put_result(t_num *stack_a, t_num *original, t_num *list_b)
{
	bool	success;

	if (lstsize(list_b))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return ;
	}
	success = is_sorting_success(stack_a, original);
	if (success)
		ft_putendl(SUCCESS_MESSAGE);
	else
		ft_putendl(FAILURE_MESSAGE);
}

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
	put_result(get_struct_list(stack_a, (size_t)argc - 1, &argv[1]), stack_b);
}
