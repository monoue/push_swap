#include "push_swap.h"
#include "libft.h"
#include "debug.h"

static bool	is_sorting_success(t_num *list_a, t_num *original)
{

}

void	put_result(t_num *list_a, t_num *original, t_num *list_b)
{
	bool	success;

	if (lstsize(list_b))
	{
		ft_putendl_err(ERROR_MESSAGE);
		return ;
	}
	success = is_sorting_success(list_a, original);
	if (success)
		ft_putendl(SUCCESS_MESSAGE);
	else
		ft_putendl(FAILURE_MESSAGE);
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
		return (EXIT_SUCCESS);
	t_num	*list_a;
	t_num	*list_b;

	list_a = get_struct_list((size_t)argc - 1, &argv[1]);
	list_b = NULL;

	print_current_status(list_a, list_b);
	exec_operation("sa", &list_a, &list_b);
	exec_operation("pb", &list_a, &list_b);
	exec_operation("pb", &list_a, &list_b);
	exec_operation("sb", &list_a, &list_b);
	put_result(get_struct_list(list_a, (size_t)argc - 1, &argv[1]), list_b);
}
