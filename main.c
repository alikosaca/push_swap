/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:19:30 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 19:09:01 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_init(t_stack **a, int ac, char **av, int *size)
{
	int		*numbers;
	int		i;

	numbers = get_arr(ac, av, size, 0);
	if (!numbers)
		error_exit();
	i = *size - 1;
	while (i >= 0)
		push(a, numbers[i--]);
	free(numbers);
}

static void	sort_algorithms(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_and_five(a, b, size);
	else
		radix_sort(a, b);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	stack_init(&a, ac, av, &size);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (1);
	}
	index_stack(&a, size);
	sort_algorithms(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
