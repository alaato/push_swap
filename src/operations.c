/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:22:44 by alaa              #+#    #+#             */
/*   Updated: 2024/03/31 04:04:28 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *from, t_stack *to, t_stack *operations)
{
	t_node	*node;
	t_node	*operation;

	node = extract_node(from);
	if (!node)
		return ;
	add_node(to, node);
	if (from->name == 'a')
		operation = create_node(PB);
	else
		operation = create_node(PA);
	add_node(operations, operation);
}

void	swap(t_stack *stack, t_stack *operations)
{
	t_node	*temp;
	t_node	*operation;

	if (stack->size == 2)
	{
		temp = stack->head;
		stack->head = stack->tail;
		stack->tail = temp;
	}
	else
	{
		temp = stack->head->next;
		stack->tail->next = temp;
		stack->head->next = temp->next;
		stack->head->prev = temp;
		temp->next->prev = stack->head;
		temp->next = stack->head;
		temp->prev = stack->tail;
		stack->head = temp;
	}
	if (stack->name == 'a')
		operation = create_node(SA);
	else
		operation = create_node(SB);
	add_node(operations, operation);
}

void	rotate(t_stack *stack, t_stack *operations)
{
	t_node	*operation;

	stack->tail = stack->head;
	stack->head = stack->head->next;
	if (stack->name == 'a')
		operation = create_node(RA);
	else
		operation = create_node(RB);
	add_node(operations, operation);
}

void	reverse_rotate(t_stack *stack, t_stack *operations)
{
	t_node	*operation;

	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->name == 'a')
		operation = create_node(RRA);
	else
		operation = create_node(RRB);
	add_node(operations, operation);
}
