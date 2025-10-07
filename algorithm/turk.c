/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:02:32 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 20:20:17 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_b(int size_b, t_sheet *sheet)
{
	int	rr_cost;
	int	rrr_cost;

	rr_cost = sheet->position_b - 1;
	rrr_cost = size_b - (sheet->position_b - 1);
	if (rr_cost < rrr_cost)
	{
		sheet->moves_b = rr_cost;
		sheet->instruction_b = "rb";
	}
	else
	{
		sheet->moves_b = rrr_cost;
		sheet->instruction_b = "rrb";
	}
}

void	get_move_plan(t_sheet *sheet, int size_a, int size_b)
{
	int	rr_cost;
	int	rrr_cost;

	rr_cost = sheet->position_a - 1;
	rrr_cost = size_a - (sheet->position_a - 1);
	if (rr_cost < rrr_cost)
	{
		sheet->moves_a = rr_cost;
		sheet->instruction_a = "ra";
	}
	else
	{
		sheet->moves_a = rrr_cost;
		sheet->instruction_a = "rra";
	}
	set_b(size_b, sheet);
}

void	double_movement(t_stack **stack_a, t_stack **stack_b, t_sheet *sheet)
{
	while (sheet->moves_a > 0 && sheet->moves_b > 0)
	{
		if (ft_strncmp("ra", sheet->instruction_a, 4) == 0
			&& ft_strncmp("rb", sheet->instruction_b, 4) == 0)
		{
			fn_rotate(stack_a, stack_b, "rr");
			sheet->moves_a--;
			sheet->moves_b--;
		}	
		else if (ft_strncmp("rra", sheet->instruction_a, 4) == 0
			&& ft_strncmp("rrb", sheet->instruction_b, 4) == 0)
		{
			fn_reverse_rotate(stack_a, stack_b, "rrr");
			sheet->moves_a--;
			sheet->moves_b--;
		}
		else
			break ;
	}
}

void	execute_movements(t_stack **stack_a, t_stack **stack_b, t_sheet sheet)
{
	if (sheet.moves_a > 0 && sheet.moves_b > 0)
		double_movement(stack_a, stack_b, &sheet);
	while (sheet.moves_a > 0)
	{
		if (ft_strncmp("ra", sheet.instruction_a, 4) == 0)
			fn_rotate(stack_a, NULL, "ra");
		if (ft_strncmp("rra", sheet.instruction_a, 4) == 0)
			fn_reverse_rotate(stack_a, NULL, "rra");
		sheet.moves_a--;
	}
	while (sheet.moves_b > 0)
	{
		if (ft_strncmp("rb", sheet.instruction_b, 4) == 0)
			fn_rotate(stack_a, stack_b, "rb");
		if (ft_strncmp("rrb", sheet.instruction_b, 4) == 0)
			fn_reverse_rotate(stack_a, stack_b, "rrb");
		sheet.moves_b--;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_sheet	sheet;
	t_cost	cost;

	clear_stack_a(stack_a, stack_b);
	while (list_size(*stack_b) > 0)
	{
		sheet = find_cheapest_move(*stack_a, *stack_b, &cost);
		get_move_plan(&sheet, list_size(*stack_a), list_size(*stack_b));
		execute_movements(stack_a, stack_b, sheet);
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
}
