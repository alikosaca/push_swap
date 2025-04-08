/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retate_reverse_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:39:24 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:39:33 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		last = *a;
		prev_last = NULL;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *a;
		*a = last;
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack **b, int print)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		last = *b;
		prev_last = NULL;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *b;
		*b = last;
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
