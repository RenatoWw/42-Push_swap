/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:33:43 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 17:28:39 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_to_rotate(t_cost *cost, char stack_id, int below)
{
	if (stack_id == 'A' && below == 1)
	{
		cost->instruction = "rra";
		cost->moves = cost->cost_a;
	}
	else if (stack_id == 'B' && below == 1)
	{
		cost->instruction = "rrb";
		cost->moves = cost->cost_b;
	}
	else if (stack_id == 'a' && below == 0)
	{
		cost->instruction = "ra";
		cost->moves = cost->cost_a;
	}
	else if (stack_id == 'B' && below == 0)
	{
		cost->instruction = "rb";
		cost->moves = cost->cost_b;
	}
}

void	set_cost(t_cost *cost, int *below, int size_a, int size_b)
{
	if (cost->position_a > size_a / 2 && cost->position_b > size_b / 2)
	{
		*below = 1;
		cost->cost_a = size_a - (cost->position_a - 1);
		cost->cost_b = size_b - (cost->position_b - 1);
	}
	else if (cost->position_a <= size_a / 2 && cost->position_b <= size_b / 2)
	{
		*below = 0;
		cost->cost_a = cost->position_a - 1;
		cost->cost_b = cost->position_b - 1;
	}
	else
	{
		if (cost->position_a <= size_a / 2 && cost->position_b > size_b / 2)
		{
			cost->cost_a = cost->position_a - 1;
			cost->cost_b = size_b - (cost->position_b - 1);
		}
		else
		{
			cost->cost_a = size_a - (cost->position_a - 1);
			cost->cost_b = cost->position_b - 1;
		}
	}
}

t_cost	*rotation_cost(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
{
	int	size_a;
	int	size_b;
	int	below;

	size_a = list_size(stack_a);
	size_b = list_size(stack_b);
	below = -1;
	set_cost(cost, &below, size_a, size_b);
	if (below != -1)
	{
		if (cost->cost_a > cost->cost_b)
			cost->total_cost = cost->cost_a;
		else
			cost->total_cost = cost->cost_b;
	}
	else
		cost->total_cost = cost->cost_a + cost->cost_b;
	stack_to_rotate(cost, 'A', below);
	stack_to_rotate(cost, 'B', below);
	return (cost);
}
