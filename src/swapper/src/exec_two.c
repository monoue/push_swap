#include "libft.h"
#include "debug.h"
#include "swapper.h"

void	exec_two(t_num *stack_a)
{
	const int	first = stack_a->num;
	const int	second = stack_a->next->num;

	if (first < second)
		return ;
	ft_putendl("sa");
}
