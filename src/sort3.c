/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:06:18 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:11:35 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_size_3(int max, int min, t_stack *stack, t_stack *operations)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
	if (head->value == max && tail->value == min)
	{
		rotate(stack, operations);
		swap(stack, operations);
	}
	else if (tail->value == max && head->next->value == min)
		swap(stack, operations);
	else if (tail->value == min && head->next->value == max)
		reverse_rotate(stack, operations);
	else if (head->value == max && head->next->value == min)
		rotate(stack, operations);
	else if (head->value == min && head->next->value == max)
	{
		swap(stack, operations);
		rotate(stack, operations);
	}
}

void	sort_top_3(int max, int min, t_stack *a, t_stack *operations)
{
	t_node	*head;
	t_node	*tail;
	t_node	*mid;

	head = a->head;
	mid = head->next;
	tail = mid->next;
	if (head->value == max && tail->value == min || head->value == max
		&& head->next->value == min || tail->value == max
		&& head->next->value == min)
		swap(a, operations);
	if (a->head->next->next->value == min && a->head->next->value == max)
	{
		rotate(a, operations);
		swap(a, operations);
		reverse_rotate(a, operations);
		swap(a, operations);
	}
	else if (a->head->value == min && a->head->next->value == max)
	{
		rotate(a, operations);
		swap(a, operations);
		reverse_rotate(a, operations);
	}
}

void	sort3_b(int max, int min, t_stack *stack, t_stack *operations)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
	if (tail->value == max && head->next->value == min)
		reverse_rotate(stack, operations);
	else if (tail->value == min && head->next->value == max)
		swap(stack, operations);
	else if (head->value == max && head->next->value == min)
	{
		swap(stack, operations);
		rotate(stack, operations);
	}
	else if (head->value == min && head->next->value == max)
		rotate(stack, operations);
	else if (is_sorted(stack, UP))
	{
		swap(stack, operations);
		reverse_rotate(stack, operations);
	}
}

void	sort3(t_stack *a, t_stack *b, char c, t_stack *operations)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	if (c == 'a')
	{
		if (is_sorted(a, UP))
			return ;
		set_min_max(&min, &max, a->head);
		if (a->size == 3)
			sort_stack_size_3(max, min, a, operations);
		else if (a->size > 3)
			sort_top_3(max, min, a, operations);
	}
	else if (c == 'b')
	{
		set_min_max(&min, &max, b->head);
		if (b->size == 3)
			sort3_b(max, min, b, operations);
		while (++i < 3)
			push(b, a, operations);
		sort_a(a, b, i, operations);
	}
}
