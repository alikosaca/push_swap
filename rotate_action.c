/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:53 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:38:56 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		first = *a;
		last = *a;
		while (last->next)
			last = last->next;
		*a = first->next;
		first->next = NULL;
		last->next = first;
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		first = *b;
		last = *b;
		while (last->next)
			last = last->next;
		*b = first->next;
		first->next = NULL;
		last->next = first;
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
