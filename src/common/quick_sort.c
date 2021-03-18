#include "push_swap.h"
#include "libft.h"

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

void		 quick_sort(int array[], int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quick_sort(array, left, pivot - 1);
		quick_sort(array, pivot + 1, right);
	}
}
