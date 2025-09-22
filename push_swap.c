/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 15:48:07 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 2)
		stack_a = fill_stack(ft_split(argv[1], ' '));
	else if (argc > 2)
		stack_a = fill_stack(argv);
	else
		return (0);
	print_list(stack_a);
	free_list(&stack_a);
	return (0);
}
