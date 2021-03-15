#include <stdio.h>
#include <limits.h>

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int array[], int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;

	i++;
	while (array[i] < array[pivot])
		i++;
	j--;
	while (array[pivot] < array[j])
		j--;
	if (i < j)
		swap(&array[i], &array[j]);
	while (i < j)
	{
		i++;
		while (array[i] < array[pivot])
			i++;
		j--;
		while (array[pivot] < array[j])
			j--;
		if (i < j)
			swap(&array[i], &array[j]);
	}
	swap(&array[pivot], &array[j]);   //pivotを更新
	return (j);
}

/* クイックソート */
void quick_sort (int array[], int left, int right) {
	int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quick_sort(array, left, pivot - 1);   // pivotを境に再帰的にクイックソート
		quick_sort(array, pivot + 1, right);
	}
}

int main (void) {
  int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  int i;

  printf("Before sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  quick_sort(array, 0, 9);

  printf("After sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  return 0;
}