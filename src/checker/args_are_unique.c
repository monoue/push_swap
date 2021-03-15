#include <push_swap.h>
#include <libft.h>

static void	int_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static void	move(int array[], int *i, int *j, int pivot)
{
	(*i)++;
	(*j)--;
	while (array[*i] < array[pivot])
		(*i)++;
	while (array[pivot] < array[*j])
		(*j)--;
	if (*i < *j)
		int_swap(&array[*i], &array[*j]);
}

static int	partition(int array[], int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	move(array, &i, &j, pivot);
	while (i < j)
		move(array, &i, &j, pivot);
	int_swap(&array[pivot], &array[j]);
	return (j);
}

static void quick_sort(int array[], int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quick_sort(array, left, pivot - 1);
		quick_sort(array, pivot + 1, right);
	}
}

static void	get_int_array(int *array, size_t num, char **strs)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		array[index] = ft_atoi(strs[index]);
		index++;
	}
}

bool		args_are_unique(size_t argc, char **argv)
{
	int		array[argc - 1];
	size_t	index;
	size_t	num;

	if (argc <= 1)
		return (false);
	num = argc - 1;
	if (num == 1)
		return (true);
	get_int_array(array, num, &argv[1]);
	quick_sort(array, 0, num - 1);
	index = 0;
	while (index < num - 1)
	{
		if (array[index] == array[index + 1])
			return (false);
		index++;
	}
	return (true);
}
