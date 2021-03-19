#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

void	set_chunk_max_nums(int chunk_max_nums[], size_t chunks_num, int sorted_array[], size_t nums_num)
{
	size_t	src_i;
	size_t	dst_i;

	src_i = 0;
	dst_i = 0;
	while (dst_i < chunks_num - 1)
	{
		chunk_max_nums[dst_i] = sorted_array[CHUNK_SIZE * (dst_i + 1) - 1];
		dst_i++;
	}
	chunk_max_nums[dst_i] = sorted_array[nums_num - 1];
}

size_t	get_chunks_num(size_t nums_num, size_t chunk_size)
{
	return (nums_num / chunk_size + (nums_num % chunk_size > 0));
}

bool	is_within_range(int num, int chunk_max_nums[], size_t chunk_i)
{
	const int	current_chunk_max = chunk_max_nums[chunk_i];
	int			prev_chunk_max;

	if (chunk_i == 0)
		return (num <= current_chunk_max);
	prev_chunk_max = chunk_max_nums[chunk_i - 1];
	return (num > prev_chunk_max && num <= current_chunk_max);
}

size_t	get_target_fore_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = stack_a;
	index = 0;
	while (tmp)
	{
		if (is_within_range(stack_a->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

size_t	get_target_back_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	size_t	index;
	t_num	*tmp;

	tmp = lstlast(stack_a);
	index = 1;
	while (tmp)
	{
		if (is_within_range(stack_a->num, chunk_max_nums, chunk_i))
			return (index);
		index++;
		tmp = tmp->prev;
	}
	return (0);
}

// 最初と最後から数える。近かった方の index を、あの関数を使って判断し、返す。
size_t	get_nearest_target_index(t_num *stack_a, int chunk_max_nums[], size_t chunk_i)
{
	const size_t	fore_index = get_target_fore_index(stack_a, chunk_max_nums, chunk_i);
	const size_t	back_index = get_target_back_index(stack_a, chunk_max_nums, chunk_i);
	const size_t	nums_num = lstsize(stack_a);

	return (get_nearer_index(fore_index, back_index, nums_num));
}

ssize_t	get_index_of_largest_num_under_designattion(t_num *stack, int designated_num)
{
	int		largest_under_designation;
	int		current_num;
	size_t	index;
	ssize_t	ret_i;
	t_num	*tmp;

	tmp = stack;
	largest_under_designation = INT_MIN;
	ret_i = NOT_FOUND;
	index = 0;
	while (tmp)
	{
		// 多分、この中にバグ
		current_num = tmp->num;
		// DSZ(index);
		// if (current_num >= largest_under_designation && current_num < designated_num)
		// 	ft_putendl("C");
		// else if (current_num >= largest_under_designation)
		// 	ft_putendl("A");
		// else if (current_num < designated_num)
		// 	ft_putendl("B");
		if (current_num >= largest_under_designation && current_num < designated_num)
		{
			ret_i = index;
			largest_under_designation = current_num;
		}
		tmp = tmp->next;
		index++;
	}
	// DSSZ(ret_i);
	return (ret_i);
}

size_t	get_index_of_largest_num(t_num *stack)
{
	t_num	*tmp;
	size_t	index;
	size_t	ret_i;
	int		largest;
	int		current_num;

	tmp = stack;
	largest = INT_MIN;
	index = 0;
	ret_i = 0;
	while (tmp)
	{
		current_num = tmp->num;
		if (current_num >= largest)
		{
			largest = current_num;
			ret_i = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (ret_i);
}

void	bring_largest_num_to_top(t_num **stack_a, t_num **stack_b, int stack_type)
{
	t_num	*stack;
	size_t	largest_num_i;

	if (stack_type == STACK_A)
		stack = *stack_a;
	else if (stack_type == STACK_B)
		stack = *stack_b;
	else
		stack = NULL;
	largest_num_i = get_index_of_largest_num(stack);
	bring_target_index_to_top(stack_a, stack_b, largest_num_i, stack_type);
}

void	set_b_for_acception(t_num **stack_a, t_num **stack_b)
{
	int		to_be_accepted;
	ssize_t	target_i;

	if (!stack_a || lstsize(*stack_a) == 0 || !stack_b || lstsize(*stack_b) < 2)
		return ;
	to_be_accepted = (*stack_a)->num;
	target_i = get_index_of_largest_num_under_designattion(*stack_b, to_be_accepted);
	if (target_i == NOT_FOUND)
		bring_largest_num_to_top(stack_a, stack_b, STACK_B);
	else
		bring_target_index_to_top(stack_a, stack_b, target_i, STACK_B);
}

// 20 個までを全部扱う。
// まず、範囲内で、先頭から一番近いものの index を検索。
// 次に、その index に応じて、A を rotate し、target を top に持ってくる。
// push_b は、される前に、適切に受け入れられるように並び替えなくてはならない。
// その並び替え方は、push される数よりも小さい数の中で、最大のものを、一番上に持ってくるというもの。
// これを、chunk の最後まで、while で回してやる。
// その最後の印は、stack_a が空、もしくは、stack_b の個数を CHUNK_SIZE で割った余りが 0 の時
void	deal_chunk_range(t_num **stack_a, t_num **stack_b, int chunk_max_nums[], size_t chunk_i)
{
	size_t	target_i;
	bool	first_try;

	first_try = true;
	while (stack_a && lstsize(*stack_a) && (first_try || lstsize(*stack_b) % CHUNK_SIZE))
	{
		first_try = false;
		target_i = get_nearest_target_index(*stack_a, chunk_max_nums, chunk_i);
		// 改良の余地としては、ここで同時に回せる。
		bring_target_index_to_top(stack_a, stack_b, target_i, STACK_A);
		set_b_for_acception(stack_a, stack_b);
		exec_and_put_operation(stack_a, stack_b, push_designated, STACK_B);

	}
	bring_largest_num_to_top(stack_a, stack_b, STACK_B);
}

// 次にやること：チャンク１つごとに、そのチャンクの最大値以内に収まる数を、１つずつ push_b していく。
// push_b は、される前に、適切に受け入れられるように並び替えなくてはならない。
// その並び替え方は、push される数よりも小さい数の中で、最大のものを、一番上に持ってくるというもの。
void	exec_one_hundred_or_less(t_num **stack_a, size_t nums_num, int sorted_array[])
{
	const size_t	chunks_num = get_chunks_num(nums_num, CHUNK_SIZE);
	int				chunk_max_nums[chunks_num];
	t_num			*stack_b;
	size_t	index;

	set_chunk_max_nums(chunk_max_nums, chunks_num, sorted_array, nums_num);
	stack_b = NULL;
	index = 0;
	while (index < chunks_num)
	{
		deal_chunk_range(stack_a, &stack_b, chunk_max_nums, index);
		index++;
	}
	while (lstsize(stack_b))
		exec_and_put_operation(stack_a, &stack_b, push_designated, STACK_A);
}
