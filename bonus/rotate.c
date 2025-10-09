/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:41:54 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 19:31:00 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_to_end(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (list_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	*stack = second;
	(*stack)->prev = NULL;
}

void	fn_rotate(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (ft_strncmp("ra", instruction, 3) == 0)
		rotate_to_end(stack_a);
	else if (ft_strncmp("rb", instruction, 3) == 0)
		rotate_to_end(stack_b);
	else if (ft_strncmp("rr", instruction, 3) == 0)
	{
		rotate_to_end(stack_a);
		rotate_to_end(stack_b);
	}
	else
		return ;
}
