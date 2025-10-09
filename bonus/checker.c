/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:26:07 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 19:57:05 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operation;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	parse_string(argc, argv);
	if (argc > 2)
		stack_a = fill_stack(argv);
	else if (argc == 2)	
		stack_a = fill_stack(ft_split(argv[1], ' '));
	size = list_size(stack_a);
	while (list_size(stack_a) != size && is_sorted(&stack_a) == 1)
	{
		operation = get_next_line(1);
		if (ft_strncmp(operation, "sa", 3) == 0)
			fn_swap(&stack_a, &stack_b, operation);
	}
	free_list(&stack_a, &stack_b);
	return (0);
}
