/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:01:47 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 15:02:10 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_target_in_a(t_stack *stack_a, int *b_value)
{
	t_stack	*temp;
	int		current_node;
	int		possible_target;
	int		minimum;

	possible_target = 2147483647;
	temp = stack_a;
	if (!b_value)
		return (-1);
	minimum = minimum_number_in_stack(stack_a);
	while (temp != NULL)
	{
		current_node = temp->content;
		if (current_node > *b_value && current_node < possible_target)
			possible_target = current_node;
		temp = temp->next;
	}
	if (possible_target == 2147483647)
		return (minimum);
	return (possible_target);
}

int	find_target_in_b(t_stack *stack_b, int *a_value)
{
	t_stack	*temp;
	int		current_node;
	int		possible_target;
	int		minimum;

	possible_target = 0;
	temp = stack_b;
	if (!a_value)
		return (-1);
	minimum = minimum_number_in_stack(stack_b);
	while (temp != NULL)
	{
		current_node = temp->content;
		if (current_node < *a_value && current_node > possible_target)
			possible_target = current_node;
		temp = temp->next;
	}
	if (possible_target == 0)
		return (minimum);
	return (possible_target);
}
