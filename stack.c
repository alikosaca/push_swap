/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:11:24 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/06 21:12:08 by akosaca          ###   ########.fr       */
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