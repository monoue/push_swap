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

int	get_designated_smallest_num_index(t_num *stack, size_t num)
{
	int	smallest_num;
	int	count;
	size_t	index;
	int	tmp;

	index = 0;
	smallest_num = get_smallest_num(stack);
	count = 1;
	while (count < num)
	{
		tmp = get_smallest_num_over_designation(stack, smallest_num);
		if (tmp <= smallest_num)
		tmp =
		smallest_num = get_smallest_num_over_designation(stack, smallest_num);
		count++;
	}
	return (smallest_num);
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

size_t	return_nearer_index()
{

}

size_t	get_nearest_index_within_nth(t_num *stack, size_t nth)
{
	size_t	n;
	size_t	nearest_index;
	size_t	tmp;
	int		target;
	size_t	target_index;

	nearest_index = LONG_MAX;
	n = nth;
	while (n > 0)
	{
		target = get_designated_smallest_num(n);
		target_index = get_target_index(target);
		// tmp = get_nearest_target_index(stack, target);
		nearest_index = get_nearer_index(nearest_index, tmp);
		n--;
	}
}

void	push_b_smallest_nums(t_num **stack_a, t_num **stack_b, size_t num)
{
	size_t	n;
	int		target;
	size_t	nearest_index;

	n = num;
	while (n > 0)
	{
		// まず、
		nearest_index = get_nearest_index_within_nth(*stack_a, num);

		// ここからは一旦無視
		// 改良の余地はある。１番目か２番目に小さいもののうち、どちらか近い方
		// target = get_designated_smallest_num(*stack_a, n);
		// bring_target_to_top(stack_a, target);
		// exec_and_put_operation()
		n--;
	}
}

// 前バージョン。一旦無視
// void	push_b_smallest_nums(t_num **stack_a, t_num **stack_b, size_t num)
// {
// 	size_t	n;
// 	int		target;
// 	size_t	nearest_index;

// 	n = num;
// 	while (n > 0)
// 	{
// 		nearest_index = get_nearest_index_within_nth(*stack_a, num);

// 		// ここからは一旦無視
// 		// 改良の余地はある。１番目か２番目に小さいもののうち、どちらか近い方
// 		// target = get_designated_smallest_num(*stack_a, n);
// 		// bring_target_to_top(stack_a, target);
// 		// exec_and_put_operation()
// 		n--;
// 	}
// }

void	exec_four_or_five(t_num **stack_a)
{
	t_num *stack_b;

	stack_b = NULL;
	push_b_smallest_nums(stack_a, &stack_b, lstsize(*stack_a) - 3);
}
