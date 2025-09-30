/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:48:34 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/30 17:19:04 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_b(t_stack *stack_b, int a_value)
{
	t_stack	*temp;
	int		bigger_betw

	while (temp != NULL)
	{
		temp = temp->next;
	}
	return (0);
}

int	get_position(t_stack *stack, int value)
{
	t_stack	*temp;

	if (value > list_size(stack))
		return (-1);
	temp = stack;
	while (--value)
		temp = temp->next;
	return (temp->index);
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
