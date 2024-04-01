/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 03:54:39 by alaa              #+#    #+#             */
/*   Updated: 2024/03/31 04:33:17 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(t_stack *stack, char name)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	stack->name = name;
	return (0);
}

int	init_program(t_program *program, t_stack *a, t_stack *b,
		t_stack *operations)
{
	init_stack(a, 'a');
	init_stack(b, 'b');
	init_stack(operations, 'o');
	program->a = a;
	program->b = b;
}
