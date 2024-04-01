/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:19:11 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:35:44 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort2(t_stack *stack, t_stack *operations)
{
	if (stack->head->value > stack->head->next->value)
		swap(stack, operations);
}

void	sort2_b(t_stack *b, t_stack *a, t_stack *operations)
{
	int	i;

	i = -1;
	if (b->head->value < b->head->next->value)
		swap(b, operations);
	while (++i < 2)
		push(b, a, operations);
}

void	sort_a(t_stack *a, t_stack *b, int len, t_stack *operations)
{
	int	mid;
	int	rotated;
	int	elems;
	int	size;

	if (len == 2 || is_sorted(a, UP))
		return (sort2(a, operations));
	else if (len == 3)
		return (sort3(a, b, 'a', operations));
	elems = len;
	mid = find_median(a, len);
	rotated = 0;
	size = a->size;
	while (len > (elems / 2 + elems % 2))
	{
		if (a->head->value < mid && --len)
			push(a, b, operations);
		else if (a->head->value >= mid && ++rotated)
			rotate(a, operations);
	}
	while (size != elems && --rotated >= 0)
		reverse_rotate(a, operations);
	sort_a(a, b, (elems / 2 + elems % 2), operations);
	sort_b(a, b, (elems / 2), operations);
}

void	sort_b(t_stack *a, t_stack *b, int len, t_stack *operations)
{
	int	mid;
	int	elems;
	int	pushed;
	int	rotated;

	if (len <= 2)
		return (sort2_b(b, a, operations));
	else if (len == 3)
		return (sort3(a, b, 'b', operations));
	mid = find_median(b, len);
	pushed = len;
	rotated = 0;
	elems = b->size;
	while (len > pushed / 2)
	{
		if (b->head->value >= mid && --len)
			push(b, a, operations);
		else if (++rotated)
			rotate(b, operations);
	}
	while (elems != pushed && --rotated >= 0)
		reverse_rotate(b, operations);
	sort_a(a, b, pushed / 2 + pushed % 2, operations);
	sort_b(a, b, pushed / 2, operations);
}

void	sort(t_stack *a, t_stack *b, t_stack *operations)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort2(a, operations);
	else if (size == 3)
		sort3(a, b, 'a', operations);
	else if (size > 3)
		sort_a(a, b, a->size, operations);
}
