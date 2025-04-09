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
void	index_stack_apply(t_stack **a, int *sorted, int size)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size && sorted[i] != temp->value)
			i++;
		if (i < size)
			temp->value = i;
		temp = temp->next;
	}
}
void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void	index_stack(t_stack **a, int size)
{
	t_stack	*temp;
	int		*sorted;
	int		i;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	temp = *a;
	i = 0;
	while (temp && i < size)
	{
		sorted[i++] = temp->value;
		temp = temp->next;
	}
	sort_array(sorted, size);
	index_stack_apply(a, sorted, size);
	free(sorted);
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

	index_stack(&a, size);

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