/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:13 by ranhaia-         ###   ########.fr       */
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

t_cost	rotation_cost(int stack_size, int position, char stack_id)
{
	int		rr_cost;
	int		rrr_cost;
	t_cost	cost;

	if (position > stack_size)
	{
		cost.moves = -1;
		return (cost);
	}
	rr_cost = position - 1;
	rrr_cost = stack_size - (position - 1);
	if (rr_cost < rrr_cost)
		cost.moves = rr_cost;
	else
		cost.moves = rrr_cost;
	stack_to_rotate(&cost, stack_id, rr_cost, rrr_cost);
	return (cost);
}

void	clear_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (list_size(*stack_a) > 3)
		fn_push_b(stack_a, stack_b);
	three_elem_sort(stack_a);
}

// void	cost_calculator(t_stack *stack_a, t_stack *stack_b)
// {
	
// }

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		position;
	t_cost	cost;

	clear_stack_a(stack_a, stack_b);
	while (list_size(*stack_b) > 0)
	{
		target = find_target_in_a(*stack_a, &(*stack_b)->content);
		position = get_position(*stack_a, target);
		cost = rotation_cost(list_size(*stack_a), position, 'A');
		rotate_calculator(stack_a, cost);
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
}
