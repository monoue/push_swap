#include "push_swap.h"
#include "debug.h"
#include "swapper.h"
#include "defs.h"
#include "libft.h"
#include "operation.h"

static size_t	get_nearness(size_t index, size_t nums_num)
{
	size_t	back_index;

	if (index >= nums_num)
		return (UINT_MAX);
	back_index = nums_num - index;
	return (ft_min_size_t(index, back_index));
}

// ２つの index のうち、どちらが先頭から近いのかを判断する関数。
// まず、近さ、つまり何回の rotate で辿り着けるかを数字で獲得。
// そして、近い方を返す。
size_t	get_nearer_index(size_t	i1, size_t i2, size_t nums_num)
{
	const size_t	nearness1 = get_nearness(i1, nums_num);
	const size_t	nearness2 = get_nearness(i2, nums_num);

	if (nearness1 < nearness2)
		return (i1);
	else
		return (i2);
}
