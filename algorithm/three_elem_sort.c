/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:52:54 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/25 19:55:06 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	two_operations(t_stack *temp, t_stack **stack)
{
	if (temp->content > temp->next->content
		&& temp->next->content > temp->next->next->content)
	{
		fn_swap(stack, NULL, "sa");
		fn_reverse_rotate(stack, NULL, "rra");
		return (1);
	}
	else if (temp->content < temp->next->content
		&& temp->content < temp->next->next->content)
	{
		fn_swap(stack, NULL, "sa");
		fn_rotate(stack, NULL, "ra");
		return (1);
	}
	return (0);
}

void	three_elem_sort(t_stack **stack)
{
	t_stack	*temp;

	if (list_size(*stack) != 3)
		return ;
	temp = *stack;
	if (two_operations(temp, stack) == 1)
		return ;
	if (temp->content > temp->next->content
		&& temp->content < temp->next->next->content)
		fn_swap(stack, NULL, "sa");
	else if (temp->content < temp->next->content
		&& temp->next->content > temp->next->next->content)
		fn_reverse_rotate(stack, NULL, "rra");
	else if (temp->next->content < temp->content
		&& temp->next->content < temp->next->next->content)
		fn_rotate(stack, NULL, "ra");
}
