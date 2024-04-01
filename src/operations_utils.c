/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:22:33 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:07:33 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_stack *stack, t_node *node)
{
	if (stack->size <= 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	node->next = stack->head;
	node->prev = stack->tail;
	stack->tail->next = node;
	stack->head->prev = node;
	stack->head = node;
	stack->size++;
}

t_node	*extract_node(t_stack *stack)
{
	t_node	*temp;

	stack->tail->next = stack->head->next;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = stack->tail;
	stack->size--;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
