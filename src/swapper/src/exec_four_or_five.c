#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

int	get_smallest_num(t_num *stack)
{
	int	smallest_num;
	t_num	*tmp;

	smallest_num = stack->num;
	tmp = stack->next;
	while (tmp)
	{
		smallest_num = ft_min_int(tmp->num, smallest_num);
		tmp = tmp->next;
	}
	return (smallest_num);
}

int	get_smallest_num_over_designation(t_num *stack, int designated_num)
{
	int		designated_smallest;
	t_num	*tmp;

	tmp = stack;
	designated_smallest = INT_MAX;
	while (tmp)
	{
		if (tmp->num <= designated_smallest && tmp->num > designated_num)
			designated_smallest = tmp->num;
		tmp = tmp->next;
	}
	return (designated_smallest);
}

int	get_nth_smallest_num(t_num *stack, size_t n)
{
	int		ret;
	size_t	count;

	ret = get_smallest_num(stack);
	count = 1;
	while (count < n)
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

size_t	get_nth_smallest_num_index(t_num *stack, size_t n)
{
	const int	nth_smallest_num = get_nth_smallest_num(stack, n);

	return (get_target_index(stack, nth_smallest_num));
}

// void	bring_target_num_to_top(t_num **stack_a, int target)
// {
// 	const size_t	target_index = get_target_index(*stack_a, target);
// 	const size_t	nums_num = lstsize(*stack_a);
// 	size_t			index;

// 	index = 0;
// 	if (target_index < nums_num / 2)
// 	{
// 		while (index < target_index)
// 		{
// 			exec_and_put_operation(stack_a, NULL, rotate_designated, rotate_a);
// 			index++;
// 		}
// 	}
// 	else
// 	{
// 		while (index + target_index < nums_num)
// 		{
// 			exec_and_put_operation(stack_a, NULL, reverse_rotate_a);
// 			index++;
// 		}
// 	}
// }

// 指定された数の範囲内の、最小の値達のうち、一番先頭から近いものの index を返す関数。
// while を回しながら、一つずつの index をとり、前に獲得した index と比べて、近い方で塗り替えていく。
// 一番近いものを返す。
size_t	get_nearest_index_within_nth_smallest_nums(t_num *stack, size_t nth)
{
	const size_t	nums_num = lstsize(stack);
	size_t			n;
	size_t			nearest_index;
	size_t			nth_num_index;

	nearest_index = LONG_MAX;
	n = nth;
	while (n > 0)
	{
		nth_num_index = get_nth_smallest_num_index(stack, n);
		nearest_index = get_nearer_index(nth_num_index, nearest_index, nums_num);
		n--;
	}
	return (nearest_index);
}


// スタックaから、指定した個数の最小の数を、bにpushする。
// そのために、インデックスを使おうとしている。
// １つずつ、指定の範囲内に収まるもののうち、一番近いもののインデックスを獲得。
// そして、それを先頭にもってきて、b に push 。
// これを while で回す。
void	push_b_smallest_nums(t_num **stack_a, t_num **stack_b, size_t num)
{
	size_t	n;
	size_t	nearest_index;

	n = num;
	while (n > 0)
	{
		nearest_index = get_nearest_index_within_nth_smallest_nums(*stack_a, n);
		bring_target_index_to_top(stack_a, stack_b, nearest_index, STACK_A);
		exec_and_put_operation(stack_a, stack_b, push_designated, STACK_B);
		n--;
	}
}

static void	bring_larger_to_top(t_num **stack_a, t_num **stack_b)
{
	const int	first = (*stack_b)->num;
	const int	second = (*stack_b)->next->num;

	if (first > second)
		return ;
	exec_and_put_operation(stack_a, stack_b, swap_designated, STACK_B);
}

void	exec_four_or_five(t_num **stack_a)
{
	const size_t	nums_num = lstsize(*stack_a);
	const size_t	diff_to_three = nums_num - 3;
	size_t			index;
	t_num			*stack_b;

	stack_b = NULL;
	push_b_smallest_nums(stack_a, &stack_b, diff_to_three);
	if (diff_to_three > 1)
		bring_larger_to_top(stack_a, &stack_b);
	exec_three(stack_a);
	index = 0;
	while (index < diff_to_three)
	{
		exec_and_put_operation(stack_a, &stack_b, push_designated, STACK_A);
		index++;
	}
}
