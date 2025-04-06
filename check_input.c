/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:15:56 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/06 20:35:41 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_atoi(char **arr, int size)
{
	int	*number_arr;
	int	i;

	number_arr = malloc(sizeof(int) * size);
	if (!number_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!is_number(arr[i]) || !is_valid_int(arr[i]))
		{
			free(number_arr);
			return (NULL);
		}
		number_arr[i] = ft_atoi(arr[i]);
		i++;
	}
	if (check_duplicates(number_arr, size))
		return (NULL);
	return (number_arr);
}

int	get_arr(int ac, char **av, int *size, int is_free)
{
	char	**arr;
	int		*number_arr;

	if (ac == 2 && av[1])
	{
		if (av[1][0] == '\0')
			return (NULL);
		arr = ft_split(av[1], ' ');
		if (!arr)
			return (NULL);
		is_free = 1;
		if (!arr[0])
		{
			free(arr);
			return (NULL);
		}
	}
	else
		arr = av + 1;
	get_arr_utils(arr, number_arr, size, is_free);
	return (number_arr);
}

void	get_arr_utils(char **arr, int *number_arr, int *size, int is_free)
{
	if (arr)
		*size = count_arr(arr, is_free);
	if (arr)
		number_arr = arr_atoi(arr, size);
	if (is_free)
		free_arr(arr);
}
int	count_arr(char **arr, int is_free)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if (i == 0)
	{
		if (is_free)
			free_arr(arr);
		return (0);
	}
	return (i);
}
