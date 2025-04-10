/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:11:27 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/06 21:13:45 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_stack	*temp;
	int		min;
	int		pos;
	int		min_pos;

	if (!stack)
		return (-1);
	temp = stack;
	min = temp->value;
	pos = 0;
	min_pos = 0;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (min_pos);
}

int	pop(t_stack **stack)
{
	t_stack	*temp;
	int		value;

	if (*stack == NULL)
		return (0);
	temp = *stack;
	value = temp->value;
	*stack = temp->next;
	free(temp);
	return (value);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}
