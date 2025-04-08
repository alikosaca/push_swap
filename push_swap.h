/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:09:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:45:52 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

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
}	t_stack;

//main
static void	stack_init(t_stack **a, t_stack **b, int ac, char **av, int *size);


//check_input
int		get_arr(int ac, char **av, int *size, int is_free);
int		count_arr(char **args, int is_free);
void	get_arr_utils(char **arr, int *number_arr, int *size, int is_free);


//check_input_utils
int	is_number(char *str);
int	is_valid_int(char *str);
int	check_duplicates(int *number_arr, int size);



//error
void	free_arr(char **arr);
void	error_exit(void);

//stack
void	push(t_stack **stack, int value);

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


#endif