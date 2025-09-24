/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:04:22 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/23 17:07:01 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_to_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (list_size(*stack) < 2)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	*stack = last;
	(*stack)->next = first;
}

void	fn_reverse_rotate(t_stack **stck_a, t_stack **stck_b, char *operation)
{
	ft_printf("%s\n", operation);
	if (ft_strncmp("rra", operation, 4) == 0)
		rotate_to_front(stck_a);
	else if (ft_strncmp("rrb", operation, 4) == 0)
		rotate_to_front(stck_b);
	else if (ft_strncmp("rrr", operation, 4) == 0)
	{
		rotate_to_front(stck_a);
		rotate_to_front(stck_b);
	}
	else
		return ;
}
