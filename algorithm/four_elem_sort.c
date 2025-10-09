/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_elem_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:23:02 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 17:14:23 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	two_first(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	if (temp->content == 1)
	{
		fn_push_b(stack_a, stack_b);
		three_elem_sort(stack_a);
		fn_push_a(stack_a, stack_b);
		return (1);
	}
	else if (temp->next->content == 1)
	{
		fn_swap(stack_a, stack_b, "sa");
		fn_push_b(stack_a, stack_b);
		three_elem_sort(stack_a);
		fn_push_a(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	four_elem_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	if (list_size(*stack_a) != 4 || is_sorted(stack_a) == 0)
		return ;
	if (two_first(temp, stack_a, stack_b) == 1)
		return ;
	if (temp->next->next->content == 1)
	{
		fn_reverse_rotate(stack_a, stack_b, "rra");
		fn_reverse_rotate(stack_a, stack_b, "rra");
		fn_push_b(stack_a, stack_b);
		three_elem_sort(stack_a);
		fn_push_a(stack_a, stack_b);
	}
	else
	{
		fn_reverse_rotate(stack_a, stack_b, "rra");
		fn_push_b(stack_a, stack_b);
		three_elem_sort(stack_a);
		fn_push_a(stack_a, stack_b);
	}
}
