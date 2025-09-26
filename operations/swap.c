/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:04:23 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/26 17:51:37 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_nodes(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = (*stack)->next;
	temp->next = temp2->next;
	if (temp->next != NULL)
		temp->next->prev = temp;
	// else
	// 	temp->next->prev = NULL;
	temp2->next = temp;
	temp->prev = temp2;
	temp2->prev = NULL;
	*stack = temp2;	
}

void	fn_swap(t_stack **stack_a, t_stack **stack_b, char *instruction)
{

	if (ft_strncmp("sa", instruction, 3) == 0)
	{
		ft_printf("%s\n", instruction);
		if (!(*stack_a) || list_size(*stack_a) < 2)
			return ;
		swap_nodes(stack_a);
	}
	else if (ft_strncmp("sb", instruction, 3) == 0)
	{
		ft_printf("%s\n", instruction);
		if (!(*stack_b) || list_size(*stack_b) < 2)
			return ;
		swap_nodes(stack_b);

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
