/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:52:54 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/23 19:24:14 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elem_sort(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (list_size(*stack) == 3)
	{
		if (temp->index == 1)
		{
			fn_swap(stack, NULL, "sa");
			fn_rotate(stack, NULL, "ra");
		}
		else if (temp->index == 2 && temp->next->index == 1)
			fn_swap(stack, NULL, "sa");
		else if (temp->index == 2 && temp->next->index == 3)
			fn_reverse_rotate(stack, NULL, "rra");
		else if (temp->index == 3 && temp->next->index == 1)
			fn_rotate(stack, NULL, "ra");
		else if (temp->index == 3 && temp->next->index == 2)
		{
			fn_swap(stack, NULL, "sa");
			fn_reverse_rotate(stack, NULL, "rra");
		}
	}
	else
		return ;
}
