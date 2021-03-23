/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:02:12 by monoue            #+#    #+#             */
/*   Updated: 2021/03/23 13:11:09 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	int_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static void	move_i(int array[], int *i, int pivot, size_t nums_num)
{
	(*i)++;
	while (*i < (int)nums_num && array[*i] < array[pivot])
		(*i)++;
}

static void	move_j(int array[], int *j, int pivot)
{
	(*j)--;
	while (*j >= 0 && array[pivot] < array[*j])
		(*j)--;
}

static int	partition(int array[], int left, int right, size_t nums_num)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	move_i(array, &i, pivot, nums_num);
	move_j(array, &j, pivot);
	if (i < j)
		int_swap(&array[i], &array[j]);
	while (i < j)
	{
		move_i(array, &i, pivot, nums_num);
		move_j(array, &j, pivot);
		if (i < j)
			int_swap(&array[i], &array[j]);
	}
	int_swap(&array[pivot], &array[j]);
	return (j);
}

void		quick_sort(int array[], int left, int right, size_t nums_num)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, nums_num);
		quick_sort(array, left, pivot - 1, nums_num);
		quick_sort(array, pivot + 1, right, nums_num);
	}
}
