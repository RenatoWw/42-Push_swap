/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:04:47 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 13:53:36 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (stack);
}
