/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:44:04 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:37:12 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_elems(int *arr, int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void	list_to_arr(int arr[], t_stack *stack, int len)
{
	int		i;
	t_node	*curr;

	i = -1;
	curr = stack->head;
	while (++i < len)
	{
		arr[i] = curr->value;
		curr = curr->next;
	}
}

int	quickselect(int arr[], int k, int len)
{
	int	pivot;
	int	left;
	int	right;

	if (len <= 1)
		return (0);
	left = 0;
	right = len - 1;
	pivot = len - 1;
	while (left < right)
	{
		while (arr[left] < arr[pivot])
			left++;
		while (arr[right] > arr[pivot])
			right--;
		if (left < right)
			swap_elems(arr, left, right);
	}
	swap_elems(arr, left, pivot);
	if (pivot > k)
		quickselect(arr, k, left);
	else if (pivot < k)
		quickselect(&arr[right], k, (len - pivot));
	else
		return (arr[pivot]);
}

int	find_median(t_stack *stack, int len)
{
	int	*arr;
	int	i;
	int	med;

	i = -1;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	list_to_arr(arr, stack, len);
	med = quickselect(arr, (len / 2), len);
	free(arr);
	return (med);
}
