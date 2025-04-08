/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:46:17 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/08 15:47:15 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int size)
{
    int		i;
    int		j;
    int		max_bits;
    int		max_num;

    max_num = find_max(*a);
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->value >> i) & 1)
                push(b, pop(a));
            else
                ra(a, 1);
            j++;
        }
        while (*b)
            push(a, pop(b));
        i++;
    }
}
