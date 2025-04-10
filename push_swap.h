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

int		*get_arr(int ac, char **av, int *size, int is_free);
int		count_arr(char **args, int is_free);

int		find_min_pos(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		ft_stacksize(t_stack *stack);

void	index_stack(t_stack **a, int size);

//check_input_utils
int		is_number(char *str);
int		is_valid_int(char *str);
int		check_duplicates(int *number_arr, int size);

int		is_sorted(t_stack *stack);
void	sort_array(int *arr, int size);
void	index_stack_apply(t_stack **a, int *sorted, int size);

//error
void	free_arr(char **arr);
void	error_exit(void);

//stack
void	push(t_stack **stack, int value);
int		pop(t_stack **stack);

//stack_utils
void	free_stack(t_stack **stack);

//small_sort
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//swap_action
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

//push_action
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

//rotate_action
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);

//rotate_reverse_action
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

//radix_sort
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		*arr_atoi(char **arr, int size);

#endif