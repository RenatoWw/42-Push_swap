/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:22:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 17:38:38 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_push_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	if (!(*stack_b))
		return ;
	insert_front(stack_a, (*stack_b)->content);
	delete_first(stack_b);
}

void	fn_push_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	if (!(*stack_a))
		return ;
	insert_front(stack_b, (*stack_a)->content);
	delete_first(stack_a);
}
