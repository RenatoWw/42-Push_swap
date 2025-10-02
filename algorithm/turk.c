/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/01 21:07:11 by ranhaia-         ###   ########.fr       */
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

void	clear_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		position;
	t_cost	cost;

	// fn_push_b(stack_a, stack_b);
	while (list_size(*stack_a) > 3)
	{
		target = find_target_in_b(*stack_b, &(*stack_a)->content);
		position = get_position(*stack_b, target);
		cost = rotation_cost(list_size(*stack_b), position);
		// turner_calculator(stack_b, cost);
		while (cost.moves > 0)
		{
			if (ft_strncmp("ra", cost.instruction, 4) == 0)
				fn_rotate(NULL, stack_b, "rb");
			if (ft_strncmp("rra", cost.instruction, 4) == 0)
				fn_reverse_rotate(NULL, stack_b, "rrb");
			cost.moves--;
		}
		fn_push_b(stack_a, stack_b);
	}
	three_elem_sort(stack_a);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		position;
	t_cost	cost;
	t_stack	*node;

	node = *stack_a;
	// usar a mesma lógica para empurrar os elementos da A para a B
	// primeiro empurrar dois, parar somente quando tiver apenas três elementos na A
	clear_stack_a(stack_a, stack_b);
	while (list_size(*stack_b) > 0)
	{
		target = find_target_in_a(*stack_a, &(*stack_b)->content);
		position = get_position(*stack_a, target);
		cost = rotation_cost(list_size(*stack_a), position);
		turner_calculator(stack_a, cost);
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
}
