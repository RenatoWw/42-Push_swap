/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_elem_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:23:02 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/23 19:59:51 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_elem_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	if (list_size(*stack_a) == 4)
	{
		if (temp->index == 1)
			fn_push_b(stack_a, stack_b);
		else if (temp->next->index == 1)
		{
			fn_swap(stack_a, stack_b, "sa");
		}
	}
}
