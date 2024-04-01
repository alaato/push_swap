/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:40:30 by alaa              #+#    #+#             */
/*   Updated: 2024/03/28 04:18:13 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(char *arg[], int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (is_num(arg[i]) == ERROR || ft_atol(arg[i]) > INT_MAX
			|| ft_atol(arg[i]) < INT_MIN)
			return (ERROR);
	}
	return (SUCESS);
}

int	fill_stack(t_stack *stack, char *input)
{
	int		len;
	t_node	*node;
	char	**arg;

	arg = ft_split(input, 32);
	if (!arg)
		return (ERROR);
	len = array_2d_len(arg);
	if (check_arg(arg, len))
	{
		free_args(arg);
		return (ERROR);
	}
	while (--len >= 0)
	{
		node = create_node(ft_atol(arg[len]));
		add_node(stack, node);
	}
	free_args(arg);
	if (is_repeating(stack) == ERROR)
		return (ERROR);
	return (0);
}

int	fill_stack_many_args(int count, char **args, t_stack *stack)
{
	int	i;

	i = count;
	while (--i > 0)
	{
		if (fill_stack(stack, args[i]) == ERROR)
		{
			free_stack(stack);
			return (ERROR);
		}
	}
}
