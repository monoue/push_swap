#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "operation.h"

int	get_smallest_num(t_num *stack)
{
	int	smallest_num;
	t_num	*tmp;

	smallest_num = stack->num;
	tmp = stack->next;
	while (tmp)
	{
		smallest_num = MIN(tmp->num, smallest_num);
		tmp = tmp->next;
	}
	return (smallest_num);
}

int	get_smallest_num_over_designation(t_num *stack, int designated_num)
{
	int	designated_smallest;
	t_num	*tmp;

	designated_smallest = INT_MAX;
	while (tmp)
	{
		if (tmp->num <= designated_smallest && tmp->num > designated_num)
			designated_smallest = tmp->num;
		tmp = tmp->next;
	}
	return (designated_smallest);
}

int	get_designated_smallest_num(t_num *stack, size_t num)
{
	int	ret;
	int	count;

	ret = get_smallest_num(stack);
	count = 1;
	while (count < num)
	{
		ret = get_smallest_num_over_designation(stack, ret);
		count++;
	}
	return (ret);
}

size_t	get_target_index(t_num *stack, int target)
{
	const size_t	nums_num = lstsize(stack);
	t_num			*tmp;
	size_t			index;

	tmp = stack;
	index = 0;
	while (index < nums_num)
	{
		if (tmp->num == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}

void	bring_target_to_top(t_num **stack_a, int target)
{
	const size_t	target_index = get_target_index(*stack_a, target);
	const size_t	nums_num = lstsize(*stack_a);
	size_t			index;

	index = 0;
	if (target_index < nums_num / 2)
	{
		while (index < target_index)
		{
			exec_and_put_operation(stack_a, NULL, rotate_a);
			index++;
		}
	}
	else
	{
		while (index + target_index < nums_num)
		{
			exec_and_put_operation(stack_a, NULL, reverse_rotate_a);
			index++;
		}
	}
}

void	puth_b_smallest_nums(t_num **stack_a, size_t num)
// void	bring_smallest_nums_to_top(t_num **stack_a, size_t num)
{
	size_t	n;
	int		target;

	n = num;
	while (n > 0)
	{
		target = get_designated_smallest_num(*stack_a, n);
		bring_target_to_top(stack_a, target);
		exec_and_put_operation()
		n--;
	}
}

// void	push_b_smallest_nums(t_num **stack_a, t_num **stack_b)
// {
// 	bring_smallest_nums_to_top(stack_a, 3);
// }

void	exec_four_or_five(t_num **stack_a)
{
	t_num *stack_b;

	stack_b = NULL;
	push_b_smallest_nums(stack_a, &stack_b);
}

void	exec(t_num **stack_a, size_t nums_num)
{
	if (is_sorted(*stack_a))
		;
	else if (nums_num == 2)
		exec_two(*stack_a);
	else if (nums_num == 3)
		exec_three(stack_a);
	else if (nums_num < 6)
		exec_four_or_five(stack_a)
}
