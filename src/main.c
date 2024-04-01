/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:23:05 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:37:21 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_index(t_stack *stack)
{
	int		i;
	int		min;
	t_node	*curr;

	i = 0;
	min = stack->head->value;
	curr = stack->head;
	while (++i < stack->size)
	{
		curr = curr->next;
		if (curr->value < min)
			min = curr->value;
	}
	return (min);
}

int	main(int arc, char **args)
{
	t_stack		a;
	t_stack		b;
	t_stack		operations;
	t_program	program;

	if (arc < 2)
		return (0);
	else
	{
		init_program(&program, &a, &b, &operations);
		if (fill_stack_many_args(arc, args, &a))
			return (error());
		sort(&a, &b, &operations);
		print_operations(&operations);
		free_stack(&a);
		free_stack(&b);
		free_stack(&operations);
	}
}
