/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 18:26:27 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	parse_string(argc, argv);
	if (argc > 2)
		stack_a = fill_stack(argv);
	else if (argc == 2)
		stack_a = fill_stack(ft_split(argv[1], ' '));
	assign_lis(stack_a);
	sort_list(&stack_a, &stack_b);
	free_list(&stack_a, &stack_b);
	return (0);
}
