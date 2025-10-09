/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elem_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:30:02 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 18:21:07 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	five_elem_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		minimum;
	int		position;

	while (list_size(*stack_a) != 3)
	{
		minimum = minimum_number_in_stack(*stack_a);
		if ((*stack_a)->content == minimum)
			fn_push_b(stack_a, stack_b);
		else
		{
			position = get_position(*stack_a, minimum);
			if (position > 2)
				fn_reverse_rotate(stack_a, stack_b, "rra");
			else
				fn_rotate(stack_a, stack_b, "ra");
		}
	}
	three_elem_sort(stack_a);
	fn_push_a(stack_a, stack_b);
	fn_push_a(stack_a, stack_b);
}
