/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:22:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/26 14:43:24 by ranhaia-         ###   ########.fr       */
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
	temp->next = *stack_a;
	*stack_a = temp;
}

void	fn_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	ft_printf("pb\n");
	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
}
