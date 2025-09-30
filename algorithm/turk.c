/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/30 12:36:21 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	maximum_number_in_stack(t_stack *stack)
{
	t_stack	*temp;
	int		maximum;

	maximum = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->content > maximum)
			maximum = temp->content;
		temp = temp->next;
	}
	return (maximum);
}

static int	minimum_number_in_stack(t_stack *stack)
{
	t_stack	*temp;
	int		minimum;

	minimum = maximum_number_in_stack(stack);
	temp = stack;
	while (temp != NULL)
	{
		if (temp->content < minimum)
			minimum = temp->content;
		temp = temp->next;
	}
	return (minimum);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		maximum_in_b;
	int		minimum_in_b;
	t_stack	*node;

	fn_push_b(stack_a, stack_b);
	fn_push_b(stack_a, stack_b);
	while (is_sorted(stack_a) == 1)
	{
		node = *stack_a;
		size = list_size(*stack_a);

		if (size == 3)
		{
			three_elem_sort(stack_a);
			break ;
		}

		maximum_in_b = maximum_number_in_stack(*stack_b);
		minimum_in_b = minimum_number_in_stack(*stack_b);
		// printf("node: %d\n", node->content);
		if ((*stack_b)->content > (*stack_b)->next->content)
			fn_rotate(stack_a, stack_b, "rb");
		if (node->content > maximum_in_b || node->content < minimum_in_b)
			fn_push_b(stack_a, stack_b);
		else
			fn_rotate(stack_a, stack_b, "rb");
			// maximum_in_b = maximum_number_in_stack(*stack_b);
			// if (node->content > maximum_in_b)
			// 	fn_push_b(stack_a, stack_b);
			// else
			// 	fn_rotate(stack_a, stack_b, "ra");
	}
	// fn_rotate(stack_a, stack_b, "rb");
	// fn_rotate(stack_a, stack_b, "rb");
	// fn_rotate(stack_a, stack_b, "rb");
	minimum_in_b = minimum_number_in_stack(*stack_b);
	fn_push_a(stack_a, stack_b);
	fn_push_a(stack_a, stack_b);
	fn_push_a(stack_a, stack_b);
	fn_push_a(stack_a, stack_b);
	printf("minimum: %d\n", minimum_in_b);
	printf("max: %d\n", maximum_in_b);
	// if (size > 3)
	// 	fn_push_b(stack_a, stack_b);
	// if (node)
	
	// }
}
