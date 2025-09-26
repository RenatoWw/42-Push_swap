/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elem_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:43:49 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/25 21:11:54 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_elem_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	temp = *stack_b;
	temp = *stack_a;
	i = 1;
	if (temp->index == 5)
	{
		fn_push_b(stack_a, stack_b);
		four_elem_sort(stack_a, stack_b);
		fn_push_a(stack_a, stack_b);
		fn_rotate(stack_a, stack_b, "ra");
	}
	else if (temp->next->index == 5)
	{
		fn_swap(stack_a, stack_b, "sa");
		fn_push_b(stack_a, stack_b);
		// four_elem_sort(stack_a, stack_b);
		// fn_push_a(stack_a, stack_b);
		// fn_rotate(stack_a, stack_b, "ra");
	}
	// if (i == 1)
	// {
	// 	fn_push_b(stack_a, stack_b);
	// 	four_elem_sort(stack_a, stack_b);
	// 	fn_push_a(stack_a, stack_b);
		
	// }
	// printf("i: %d\n", i);
}
