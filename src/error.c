/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:40:30 by alaa              #+#    #+#             */
/*   Updated: 2024/04/02 00:55:28 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (ERROR);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;
	int		i;

	curr = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

void	free_args(char **args)
{
	int	i;

	i = array_2d_len(args);
	while (--i >= 0)
		free(args[i]);
	free(args);
}
