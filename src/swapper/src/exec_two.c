#include "libft.h"
#include "debug.h"
#include "swapper.h"
#include "operation.h"

void	exec_two(t_num *stack_a)
{
	const int	first = stack_a->num;
	const int	second = stack_a->next->num;

	if (first < second)
		return ;
	exec_and_put_operation(&stack_a, NULL, swap_a);
}
