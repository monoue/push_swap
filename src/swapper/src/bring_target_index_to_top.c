#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

// void	bring_target_index_to_top(t_num **stack_a, t_num **stack_b, size_t target_index, int stack_type)
// {
// 	const size_t	nums_num = lstsize(*stack_a);
// 	size_t			index;

// 	if (target_index == 0)
// 		return ;
// 	index = 0;
// 	if (target_index < nums_num / 2)
// 	{
// 		while (index < target_index)
// 		{
// 			exec_and_put_operation(stack_a, stack_b, rotate_designated, stack_type);
// 			index++;
// 		}
// 	}
// 	else
// 	{
// 		while (index + target_index < nums_num)
// 		{
// 			exec_and_put_operation(stack_a, stack_b, reverse_rotate_designated, stack_type);
// 			index++;
// 		}
// 	}
// }

void	bring_target_index_to_top(t_num **stack_a, t_num **stack_b, size_t target_index, int stack_type)
{
	size_t	nums_num;
	if (stack_type == STACK_A)
		nums_num = lstsize(*stack_a);
	else
		nums_num = lstsize(*stack_b);
	size_t			index;

	if (target_index == 0)
		return ;
	index = 0;
	if (target_index <= nums_num / 2)
	{
		while (index < target_index)
		{
			exec_and_put_operation(stack_a, stack_b, rotate_designated, stack_type);
			index++;
		}
	}
	else
	{
		while (index + target_index < nums_num)
		{
			exec_and_put_operation(stack_a, stack_b, reverse_rotate_designated, stack_type);
			index++;
		}
	}
}