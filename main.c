/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:30 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/06 21:18:31 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

static void	stack_init(t_stack **a, t_stack **b, int ac, char **av, int *size)
{
	int		*numbers;
	int		i;

	numbers = get_arr(ac, av, &size, 0);
	if (!numbers)
		error_exit();
	i = size - 1;
	*a = NULL;
	*b = NULL;
	while (i >= 0)
		push(a, numbers[i--]);
	free(numbers);
}

static void	choose_algorithm(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b, size);
}


int main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int		*size;

	stack_init(&a, &b, ac, av, &size);
	
	if (is_sorted(a))
	{
		free_stack(&a);
		return (1);
	}
	sort_algorithms(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}