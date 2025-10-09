/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:32:26 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 17:58:21 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (is_sorted(stack_a) == 0)
		return ;
	else if (size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		fn_swap(stack_a, NULL, "sa");
	else if (size == 3)
		three_elem_sort(stack_a);
	else if (size == 4)
		four_elem_sort(stack_a, stack_b);
	else if (size == 5)
		five_elem_sort(stack_a, stack_b);
	else if (size > 5)
		turk_sort(stack_a, stack_b);
	else
		return ;
}
