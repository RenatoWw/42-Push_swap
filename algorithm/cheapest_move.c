/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:00:23 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 16:55:48 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_sheet	find_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	cost;
	t_stack	*temp;
	t_sheet	sheet;

	sheet.cheapest_cost = 2147483647;
	temp = stack_b;
	while (temp != NULL)
	{
		cost.target_in_a = find_target_in_a(stack_a, &temp->content);
		cost.position_b = get_position(temp, temp->content);
		cost.position_a = get_position(stack_a, cost.target_in_a);
		rotation_cost(list_size(stack_b), &cost, 'B');
		rotation_cost(list_size(stack_a), &cost, 'A');
		cost.total_cost = cost.cost_a + cost.cost_b;
		if (cost.total_cost < sheet.cheapest_cost)
		{
			sheet.cheapest_cost = cost.total_cost;
			sheet.target_node_to_move = temp->content;
			sheet.target_in_a = cost.target_in_a;
		}
		temp = temp->next;
	}
	sheet.position_a = get_position(stack_a, sheet.target_in_a);
	sheet.position_b = get_position(stack_b, sheet.target_node_to_move);
	return (sheet);
}
