#include <push_swap.h>
#include <libft.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!args_are_valid((size_t)argc, argv))
	{
		ft_putendl_err("Error");
		return (EXIT_SUCCESS);
	}
}