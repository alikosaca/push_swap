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
