#include <push_swap.h>
#include <libft.h>
#include <debug.h>

int	main(int argc, char *argv[])
{
	t_num	*list_a;
	t_num	*list_b;
	char	*line;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!args_are_valid((size_t)argc, argv))
	{
		ft_putendl_err("Error");
		return (EXIT_SUCCESS);
	}
	list_a = get_struct_list((size_t)argc - 1, &argv[1]);
	list_b = NULL;
	while (get_next_line(STDIN_FILENO, &line) >= 0)
	{
		if (!is_valid_operator(line))
		{
			ft_putendl_err("Error");
			exit(EXIT_SUCCESS);
		}
		exec_operation(line, &list_a, &list_b);
		SAFE_FREE(line);
	}
}
