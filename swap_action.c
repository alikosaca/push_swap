/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:33:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:33:41 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = temp;
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack **b, int print)
{
	int	temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = temp;
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
