/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elem_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:43:49 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/26 18:46:14 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_smallest(t_stack *stack)
{
	t_stack	*temp;
	int		smallest;

	temp = stack;
	smallest = stack->index;
	printf("smallest: %d\n", smallest);
}

void	five_elem_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		medium;
	int		biggest;
	int		smallest;

	medium = (*stack_a)->next->next->index;
	temp_a = *stack_a;
	while (list_size(*stack_a) != 3)
	{
		if (temp_a->index >= medium)
			fn_rotate(stack_a, stack_b, "ra");	
		else if (temp_a->index < medium)
			fn_push_b(stack_a, stack_b);
	}
	three_elem_sort(stack_a);
	temp_b = *stack_b;
	biggest = temp_b->index;
	smallest = 0;
	while (temp_a != NULL)
	{
		if (temp_b->index < temp_a->index)
			smallest++;
		temp_a = temp_a->next;
	}
	if (smallest == 0)
		fn_push_a(stack_a, stack_b);
	// printf("%d, %d\n", temp_b->index, temp_a->index);
	get_smallest(*stack_a);
}
