/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:19:00 by alaa              #+#    #+#             */
/*   Updated: 2024/03/28 04:19:01 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			name;
}					t_stack;

typedef struct program
{
	t_stack			*a;
	t_stack			*b;
	int				operation_count;

}					t_program;