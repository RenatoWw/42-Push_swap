/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:04:23 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/23 17:03:26 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fn_swap(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	int	temp;

	if (ft_strncmp("sa", instruction, 3) == 0)
	{
		ft_printf("%s\n", instruction);
		if (!(*stack_a) || list_size(*stack_a) < 2)
			return ;
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
	else if (ft_strncmp("sb", instruction, 3) == 0)
	{
		ft_printf("%s\n", instruction);
		if (!(*stack_b) || list_size(*stack_b) < 2)
			return ;
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
	else if (ft_strncmp("ss", instruction, 3) == 0)
		fn_swap_ss(stack_a, stack_b);
}

void	fn_swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	ft_printf("ss\n");
	if (!(!(*stack_a) || list_size(*stack_a) < 2))
	{
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
	if (!(!(*stack_b) || list_size(*stack_b) < 2))
	{
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
}
