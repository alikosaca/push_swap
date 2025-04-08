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

static void	stack_init(t_stack **a, t_stack **b, int ac, char **av, int *size)
{
	int		*numbers;
	int		i;

	numbers = get_arr(ac, av, size, 0);
	if (!numbers)
		error_exit();
	i = *size - 1;
	*a = NULL;
	*b = NULL;
	while (i >= 0)
		push(a, numbers[i--]);
	free(numbers);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack || !stack->next)
		return (1);
	temp = stack;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	sort_algorithms(t_stack **a, t_stack **b, int size)
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
		radix_sort(a, b);
}

int main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int		size;

	stack_init(&a, &b, ac, av, &size);
	
	if (is_sorted(a))
	{
		free_stack(&a);
		return (1);
	}
	sort_algorithms(&a, &b, size);
	t_stack *temp = a;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}