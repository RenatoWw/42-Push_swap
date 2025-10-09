/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_idx_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:27:56 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/07 18:55:57 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_lis(int *lis_arr, int size)
{
	int	max_lis;
	int	i;

	max_lis = 0;
	i = 0;
	while (i < size)
	{
		if (max_lis < lis_arr[i])
			max_lis = lis_arr[i];
		i++;
	}
	return (max_lis);
}

int	get_max_position(int *lis_arr, int max_lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lis_arr[i] == max_lis)
			break ;
		i++;
	}
	return (i);
}

int	*revert_arr(int *idx_arr, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = idx_arr[i];
		idx_arr[i] = idx_arr[size - i - 1];
		idx_arr[size - i - 1] = temp;
		i++;
	}
	return (idx_arr);
}

int	*create_index_arr(int *aux_arr, int *lis_arr, int size)
{
	t_lis	lis;
	int		*idx_arr;
	int		i;
	int		j;

	lis.max_lis = get_max_lis(lis_arr, size);
	lis.max_pos = get_max_position(lis_arr, lis.max_lis, size);
	idx_arr = malloc(lis.max_lis * sizeof(int));
	i = lis.max_pos;
	idx_arr[0] = lis.max_pos;
	lis.last_n_found = aux_arr[lis.max_pos];
	j = 1;
	while (i >= 0)
	{
		if (lis_arr[i] == (lis.max_lis - 1) && aux_arr[i] < lis.last_n_found)
		{
			idx_arr[j++] = i;
			lis.last_n_found = aux_arr[i];
			lis.max_lis--;
		}
		i--;
	}
	free(aux_arr);
	revert_arr(idx_arr, get_max_lis(lis_arr, size));
	return (idx_arr);
}
