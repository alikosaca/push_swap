/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:43:52 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/09 08:17:10 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_max_pos(t_stack *stack)
{
	t_stack	*temp;
	int		max;
	int		pos;
	int		max_pos;

	if (!stack)
		return (-1);
	max = stack->value;
	pos = 0;
	max_pos = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (max_pos);
}

