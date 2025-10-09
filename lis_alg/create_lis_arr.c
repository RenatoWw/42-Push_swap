/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:38:59 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/07 17:26:06 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*create_aux_arr(t_stack *stack)
{
	t_stack	*temp;
	int		size;
	int		*aux_arr;
	int		i;

	aux_arr = malloc(list_size(stack) * sizeof(int));
	temp = stack;
	size = list_size(temp);
	i = 0;
	while (temp != NULL)
	{
		aux_arr[i++] = temp->content;
		temp = temp->next;
	}
	return (aux_arr);
}

int	*fill_lis_arr(int *lis_arr, int *aux_arr, int size)
{
	int	i;
	int	j;
	int	new_len;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (aux_arr[j] < aux_arr[i])
			{
				new_len = lis_arr[j] + 1;
				if (new_len > lis_arr[i])
					lis_arr[i] = new_len;
			}
			j++;
		}
		i++;
	}
	return (lis_arr);
}

int	*calculate_lis(t_stack *stack)
{
	int		*aux_arr;
	int		*lis_arr;
	int		i;
	int		size;

	size = list_size(stack);
	lis_arr = malloc(size * sizeof(int));
	aux_arr = create_aux_arr(stack);
	i = 0;
	while (i < size)
		lis_arr[i++] = 1;
	lis_arr = fill_lis_arr(lis_arr, aux_arr, size);
	free(aux_arr);
	return (lis_arr);
}
