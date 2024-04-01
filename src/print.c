/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:07:22 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:49:39 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	int		i;
	t_node	*curr;

	i = -1;
	curr = stack->head;
	write(1, "here is stack ", 15);
	write(1, &stack->name, 1);
	while (++i < stack->size)
	{
		ft_argument_c(32);
		ft_putnbr_fd(curr->value, 1);
		curr = curr->next;
	}
	ft_putchar_fd(10, 1);
}

void	print_operations(t_stack *operations)
{
	int		i;
	t_node	*curr;

	i = -1;
	curr = operations->tail;
	while (++i < operations->size)
	{
		if (((curr->value == PB && curr->prev->value == PA)
				|| (curr->value == PA && curr->prev->value == PB)
				|| (curr->value == RRA && curr->prev->value == RA)
				|| (curr->value == RRB && curr->prev->value == RB))
			&& curr->prev != operations->tail)
		{
			curr = curr->prev;
			i++;
		}
		else if (curr->value == SA && curr->prev->value == SB)
		{
			print_operation(SS);
			curr = curr->prev;
			i++;
		}
		else
			print_operation(curr->value);
		curr = curr->prev;
	}
}

int	redundant(t_node *curr, t_stack *operations)
{
	return (((curr->value == PB && curr->prev->value == PA)
			|| (curr->value == PA && curr->prev->value == PB)
			|| (curr->value == RRA && curr->prev->value == RA)
			|| (curr->value == RRB && curr->prev->value == RB))
		&& curr->prev != operations->tail);
}

void	print_operation(int value)
{
	if (value == PA)
		ft_printf("pa\n");
	else if (value == PB)
		ft_printf("pb\n");
	else if (value == SA)
		ft_printf("sa\n");
	else if (value == SB)
		ft_printf("sb\n");
	else if (value == RA)
		ft_printf("ra\n");
	else if (value == RB)
		ft_printf("rb\n");
	else if (value == RRA)
		ft_printf("rra\n");
	else if (value == RRB)
		ft_printf("rrb\n");
	else if (value == SS)
		ft_printf("ss\n");
	else if (value == RR)
		ft_printf("rr\n");
	else if (value == RRR)
		ft_printf("rrr\n");
}
