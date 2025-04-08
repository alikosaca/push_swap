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
