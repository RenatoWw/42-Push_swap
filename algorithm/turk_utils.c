/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:48:34 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/30 21:09:15 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_position(t_stack *stack, int content)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = 1;
	while (temp != NULL)
	{
		if (temp->content == content)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

t_cost	rotation_cost(int stack_size, int position)
{
	int		ra_cost;
	int		rra_cost;
	t_cost	cost;

	if (position > stack_size)
	{
		cost.moves = -1;
		cost.instruction = "";
		return (cost);
	}
	ra_cost = position - 1;
	rra_cost = stack_size - (position - 1);
	if (ra_cost < rra_cost)
	{
		cost.moves = ra_cost;
		cost.instruction = "ra";
		return (cost);
	}
	else
	{
		cost.moves = rra_cost;
		cost.instruction = "rra";
		return (cost);
	}
}
