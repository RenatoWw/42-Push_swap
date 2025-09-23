/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 21:15:14 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		stack_a = fill_stack(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack_a = fill_stack(argv);
	else
		return (0);
	fn_push_b(&stack_a, &stack_b);
	fn_push_b(&stack_a, &stack_b);
	fn_push_b(&stack_a, &stack_b);
	fn_push_b(&stack_a, &stack_b);
	print_list(stack_a, stack_b);
	fn_rotate(&stack_a, &stack_b, "ra");
	fn_rotate(&stack_a, &stack_b, "ra");
	fn_rotate(&stack_a, &stack_b, "ra");
	fn_rotate(&stack_a, &stack_b, "rr");
	fn_rotate(&stack_a, &stack_b, "rr");
	print_list(stack_a, stack_b);
	free_list(&stack_a, &stack_b);
	return (0);
}
