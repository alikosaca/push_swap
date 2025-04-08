/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:36:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:36:46 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	if (!is_empty(*b))
	{
		push(a, pop(b));
		if (print)
			ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack **a, t_stack **b, int print)
{
	if (!is_empty(*a))
	{
		push(b, pop(a));
		if (print)
			ft_putstr_fd("pb\n", 1);
	}
}
