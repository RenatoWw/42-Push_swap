/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:04:47 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/07 19:58:22 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack **stack)
{
	t_stack	*temp;
	int		index_value;

	temp = *stack;
	index_value = 1;
	while (temp != NULL)
	{
		temp->index = index_value;
		index_value++;
		temp = temp->next;
	}
}

t_stack	*fill_stack(char **numbers)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	parse_numbers(numbers);
	check_duplicates(numbers);
	if (ft_strncmp(numbers[0], "./push_swap", 11) == 0)
	{
		stack = create_node(ft_atol(numbers[1]));
		i = 2;
	}
	else
		i = 0;
	while (numbers[i])
	{
		insert_back(&stack, ft_atol(numbers[i++]));
	}
	if (ft_strncmp(numbers[0], "./push_swap", 11))
		free_split(numbers);
	fill_index(&stack);
	return (stack);
}
