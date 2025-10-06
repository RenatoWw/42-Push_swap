/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 19:04:48 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_rotate(t_cost *cost, char stack_id, int rr_cost, int rrr_cost)
{
	if (stack_id == 'A' && cost->moves == rr_cost)
	{
		cost->instruction = "ra";
		cost->cost_a = cost->moves;
	}
	else if (stack_id == 'A' && cost->moves == rrr_cost)
	{
		cost->instruction = "rra";
		cost->cost_a = cost->moves;
	}
	else if (stack_id == 'B' && cost->moves == rr_cost)
	{
		cost->instruction = "rb";
		cost->cost_b = cost->moves;
	}
	else if (stack_id == 'B' && cost->moves == rrr_cost)
	{
		cost->instruction = "rrb";
		cost->cost_b = cost->moves;
	}
}

t_cost	*rotation_cost(int stack_size, t_cost *cost, char stack_id)
{
	int		rr_cost;
	int		rrr_cost;
	int		position;

	if (stack_id == 'A')
		position = cost->position_a;
	else
		position = cost->position_b;
	if (position > stack_size)
	{
		cost->moves = -1;
		return (cost);
	}
	rr_cost = position - 1;
	rrr_cost = stack_size - (position - 1);
	if (rr_cost < rrr_cost)
		cost->moves = rr_cost;
	else
		cost->moves = rrr_cost;
	stack_to_rotate(cost, stack_id, rr_cost, rrr_cost);
	return (cost);
}

void	clear_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (list_size(*stack_a) > 3)
		fn_push_b(stack_a, stack_b);
	three_elem_sort(stack_a);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	// int		target;
	// int		position;
	// t_cost	*cost;

	clear_stack_a(stack_a, stack_b);
	while (list_size(*stack_b) > 0)
	{
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
}
