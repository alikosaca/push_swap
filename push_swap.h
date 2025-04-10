/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:09:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 19:09:42 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

int		*arr_atoi(char **arr, int size);
int		*get_arr(int ac, char **av, int *size, int is_free);
int		count_arr(char **args, int is_free);

int		find_min_pos(t_stack *stack);
int		pop(t_stack **stack);
void	free_stack(t_stack **stack);

int		find_max_pos(t_stack *stack);

int		ft_stacksize(t_stack *stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

void	index_stack(t_stack **a, int size);
void	index_stack_apply(t_stack **a, int *sorted, int size);
void	sort_array(int *arr, int size);
int		is_sorted(t_stack *stack);
void	push(t_stack **stack, int value);

int		is_number(char *str);
int		is_valid_int(char *str);
int		check_duplicates(int *number_arr, int size);

void	free_arr(char **arr);
void	error_exit(void);

void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four_and_five(t_stack **a, t_stack **b, int size);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);

#endif