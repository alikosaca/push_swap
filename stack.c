/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:11:24 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 17:46:12 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return ;
	new_stack->value = value;
	new_stack->next = *stack;
	*stack = new_stack;
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

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
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
