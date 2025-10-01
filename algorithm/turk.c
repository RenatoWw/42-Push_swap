/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/01 16:47:08 by ranhaia-         ###   ########.fr       */
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
	while (list_size(*stack_a) != 3)
		fn_push_b(stack_a, stack_b);
	three_elem_sort(stack_a);
}

void	stack_gap_opener(t_stack **stack_a, t_cost cost)
{
	while (cost.moves > 0)
	{
		if (ft_strncmp("ra", cost.instruction, 4) == 0)
			fn_rotate(stack_a, NULL, "ra");
		if (ft_strncmp("rra", cost.instruction, 4) == 0)
			fn_reverse_rotate(stack_a, NULL, "rra");
		cost.moves--;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		position;
	t_cost	cost;
	t_stack	*node;

	node = *stack_a;
	clear_stack_a(stack_a, stack_b);
	while (list_size(*stack_b) > 0)
	{
		target = find_target_in_a(*stack_a, &(*stack_b)->content);
		position = get_position(*stack_a, target);
		cost = rotation_cost(list_size(*stack_a), position);
		stack_gap_opener(stack_a, cost);
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
}
