/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:22:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 17:25:06 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fn_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	ft_printf("pa\n");
	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	if ((*stack_a)->next != NULL)
		(*stack_a)->next->prev = temp;
	(*stack_a)->prev = NULL;
}

void	fn_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	ft_printf("pb\n");
	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	if ((*stack_b)->next != NULL)
		(*stack_b)->next->prev = temp;
	(*stack_b)->prev = NULL;
}
