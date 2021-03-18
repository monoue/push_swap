#include <push_swap.h>
#include <libft.h>
#include <debug.h>

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
