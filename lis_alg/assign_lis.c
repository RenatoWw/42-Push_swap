/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:59:11 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 18:26:11 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_lis_to_zero(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		temp->is_in_lis = 0;
		temp = temp->next;
	}
}

void	assign_lis(t_stack *stack_a)
{
	t_stack	*temp;
	int		*lis_arr;
	int		*idx_arr;
	int		j;
	int		size;

	size = list_size(stack_a);
	lis_arr = calculate_lis(stack_a);
	idx_arr = create_index_arr(create_aux_arr(stack_a), lis_arr, size);
	set_lis_to_zero(stack_a);
	temp = stack_a;
	while (temp != NULL)
	{
		j = 0;
		while (j < get_max_lis(lis_arr, size))
		{
			if (temp->index == idx_arr[j] + 1)
				temp->is_in_lis = 1;
			j++;
		}
		temp = temp->next;
	}
	free(lis_arr);
	free(idx_arr);
}
