/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:18:58 by alaa              #+#    #+#             */
/*   Updated: 2024/04/01 19:20:23 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./structs.h"
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ERROR 1
#define SUCESS 0
#define UP 0
#define DOWN 1
#define PB 2
#define PA 3
#define SB 4
#define SA 5
#define RB 6
#define RA 7
#define RRB 8
#define RRA 9
#define SS 10
#define RR 11
#define RRR 12

// init
void	add_node(t_stack *stack, t_node *node);
int		init_stack(t_stack *stack, char name);
t_node	*create_node(int value);
void	print_stack(t_stack *stack);
int		init_program(t_program *program, t_stack *a, t_stack *b,
			t_stack *operations);

// operations
void	push(t_stack *from, t_stack *to, t_stack *operations);
void	swap(t_stack *stack, t_stack *operations);
t_node	*extract_node(t_stack *stack);
void	rotate(t_stack *stack, t_stack *operations);
void	reverse_rotate(t_stack *stack, t_stack *operations);
void	print_operations(t_stack *operations);

int		redundant(t_node *curr, t_stack *operations);

void	print_operation(int value);
// find_median.c
int		find_median(t_stack *stack, int len);
void	list_to_arr(int arr[], t_stack *stack, int len);

// sort.c
void	set_min_max(int *min, int *max, t_node *head);
void	sort3(t_stack *a, t_stack *b, char c, t_stack *operations);
void	sort_stack_size_3(int max, int min, t_stack *stack,
			t_stack *operations);
void	sort2(t_stack *stack, t_stack *operations);
void	sort_b(t_stack *a, t_stack *b, int len, t_stack *operations);
void	small(t_stack *b, int len, t_stack *a, t_stack *operations);
void	sort_a(t_stack *a, t_stack *b, int len, t_stack *operations);

// sort utils
void	set_min_max(int *min, int *max, t_node *head);
int		is_sorted(t_stack *stack, int dir);
void	sort(t_stack *a, t_stack *b, t_stack *operations);
int		find_min(t_stack *stack);

// parse.c
int		fill_stack(t_stack *stack, char *input);
int		fill_stack_many_args(int count, char **args, t_stack *stack);
// int		str_to_int(char *str, int numbers[], int len);

// check_args.c
int		array_2d_len(char **arr);
int		is_num(char *arr);
int		is_repeating(t_stack *stack);
int		fill_int_arr(char *args[], int size, int numbers[]);

// error.c
int		error(void);
void	free_stack(t_stack *stack);
void	free_args(char **args);