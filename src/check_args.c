/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:34:58 by alaa              #+#    #+#             */
/*   Updated: 2024/04/02 01:02:20 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	array_2d_len(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

int	is_num(char *arr)
{
	int	i;

	i = -1;
	if (ft_strlen(arr) == 1 && arr[0] == '-')
		return (ERROR);
	if (arr[0] == '-')
		i++;
	while (arr[++i])
	{
		if (!ft_isdigit(arr[i]))
			return (ERROR);
	}
	return (SUCESS);
}

int	fill_int_arr(char *args[], int size, int numbers[])
{
	int	i;

	i = -1;
	if (!numbers)
		return (ERROR);
	while (++i < size)
		numbers[i] = ft_atol(args[i]);
	return (SUCESS);
}

int	is_repeating(t_stack *stack)
{
	int		i;
	int		j;
	int		dup;
	t_node	*curr;
	t_node	*prev;

	i = -1;
	dup = 0;
	curr = stack->head;
	while (++i < stack->size)
	{
		j = -1;
		prev = curr->prev;
		while (++j < i)
		{
			if (curr->value == prev->value)
				dup = 1;
			prev = prev->prev;
		}
		if (dup == 1)
			break ;
		curr = curr->next;
	}
	return (dup);
}
