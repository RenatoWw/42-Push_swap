/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/30 16:57:28 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_cost	cost;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 2)
		stack_a = fill_stack(argv);
	else if (argc == 2)
		stack_a = fill_stack(ft_split(argv[1], ' '));
	// print_list(stack_a, stack_b);
	// // sort_list(&stack_a, &stack_b);
	// fn_push_b(&stack_a, &stack_b);
	// fn_push_b(&stack_a, &stack_b);
	// fn_push_a(&stack_a, &stack_b);
	print_list(stack_a, stack_b);
	cost = rotation_cost(list_size(stack_a), 7);
	printf("cost: %d\noperation: %s", cost.moves, cost.instruction);
	// get_lis_length(&stack_a);
	free_list(&stack_a, &stack_b);
	return (0);
}
