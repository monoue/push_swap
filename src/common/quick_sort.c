#include "push_swap.h"
#include "libft.h"
#include "debug.h"

static void	int_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// 元のもの。ここから
// static void	move(int array[], int *i, int *j, int pivot)
// {
// 	(*i)++;
// 	(*j)--;
// 	while (array[*i] < array[pivot])
// 		(*i)++;
// 	while (array[pivot] < array[*j])
// 		(*j)--;
// 	if (*i < *j)
// 		int_swap(&array[*i], &array[*j]);
// }

// static int	partition(int array[], int left, int right)
// {
// 	int	i;
// 	int	j;
// 	int	pivot;

// 	i = left;
// 	j = right + 1;
// 	pivot = left;
// 	move(array, &i, &j, pivot);
// 	while (i < j)
// 		move(array, &i, &j, pivot);
// 	int_swap(&array[pivot], &array[j]);
// 	return (j);
// }

// void		 quick_sort(int array[], int left, int right)
// {
// 	int	pivot;

// 	if (left < right)
// 	{
// 		pivot = partition(array, left, right);
// 		quick_sort(array, left, pivot - 1);
// 		quick_sort(array, pivot + 1, right);
// 	}
// }
// 元のもの。ここまで

static void	move(int array[], int *i, int *j, int pivot, size_t nums_num)
{
	(*i)++;
	(*j)--;
	while (*i < (int)nums_num && array[*i] < array[pivot])
		(*i)++;
	while (*j >= 0 && array[pivot] < array[*j])
		(*j)--;
	if (*i < *j)
		int_swap(&array[*i], &array[*j]);
}

static int	partition(int array[], int left, int right, size_t nums_num)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	move(array, &i, &j, pivot, nums_num);
	while (i < j)
		move(array, &i, &j, pivot, nums_num);
	int_swap(&array[pivot], &array[j]);
	return (j);
}

void		 quick_sort(int array[], int left, int right, size_t nums_num)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, nums_num);
		quick_sort(array, left, pivot - 1, nums_num);
		quick_sort(array, pivot + 1, right, nums_num);
	}
}