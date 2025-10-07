/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:48:34 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 20:20:26 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack_a(t_stack **stack)
{
	t_stack	*temp;
	t_cost	cost;

	temp = *stack;
	cost.position_a = get_position(temp, minimum_number_in_stack(temp));
	rotation_cost(list_size(temp), &cost, 'A');
	while (cost.moves > 0)
	{
		if (ft_strncmp("ra", cost.instruction, 4) == 0)
			fn_rotate(stack, NULL, "ra");
		if (ft_strncmp("rra", cost.instruction, 4) == 0)
			fn_reverse_rotate(stack, NULL, "rra");
		cost.moves--;
	}
}

void	clear_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (list_size(*stack_a) > 3)
		fn_push_b(stack_a, stack_b);
	three_elem_sort(stack_a);
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

int	maximum_number_in_stack(t_stack *stack)
{
	t_stack	*temp;
	int		maximum;

	maximum = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->content > maximum)
			maximum = temp->content;
		temp = temp->next;
	}
	return (maximum);
}

int	minimum_number_in_stack(t_stack *stack)
{
	t_stack	*temp;
	int		minimum;

	minimum = maximum_number_in_stack(stack);
	temp = stack;
	while (temp != NULL)
	{
		if (temp->content < minimum)
			minimum = temp->content;
		temp = temp->next;
	}
	return (minimum);
}
