/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:30:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:44:59 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && first > third)
		ra(a, 1);
	else if (first < second && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (second > first && second > third)
		rra(a, 1);
	else if (first > second)
		sa(a, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	if (min_pos == 1)
		sa(a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_pos == 3)
		rra(a, 1);
	if (is_sorted(*a))
		return ;
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	if (min_pos == 1)
		sa(a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_pos == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (min_pos == 4)
		rra(a, 1);
	if (is_sorted(*a))
		return ;
	pb(a, b, 1);
	sort_four(a, b);
	pa(a, b, 1);
}
