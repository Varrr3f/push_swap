/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:55:24 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:55:27 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort_help(int *array, int left, int pivot)
{
	array[left] = pivot;
	pivot = left;
	return (pivot);
}

void	quick_sort(int *array, int left, int right)
{
	int	pivot;
	int	l_hold;
	int	r_hold;

	l_hold = left;
	r_hold = right;
	pivot = array[left];
	while (left < right)
	{
		while ((array[right] >= pivot) && (left < right))
			right--;
		if (left != right)
			array[left++] = array[right];
		while ((array[left] <= pivot) && (left < right))
			left++;
		if (left != right)
			array[right--] = array[left];
	}
	pivot = quick_sort_help(array, left, pivot);
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quick_sort(array, left, pivot - 1);
	if (right > pivot)
		quick_sort(array, pivot + 1, right);
}
