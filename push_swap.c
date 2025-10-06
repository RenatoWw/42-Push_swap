/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 19:14:02 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ----------------- FEITO
// arrumar função REVERSE_ROTATE - RRA
// ----------------- FEITO

// ----------------- FEITO
// criar função para rotacionar a A até o minimo ficar no topo
// FAZER O CALCULO PRA VER SE É MELHOR USAR RA ou RRA
// // while (stack_a->content != minimum_number_in_stack(stack_a))
// // 	fn_rotate(&stack_a, &stack_b, "ra");
// ----------------- FEITO

// ----------------- FEITO
// criar função para mandar todos os elementos para B
// até ficar somente 3 na A
// ----------------- FEITO

// ----------------- FEITO
// revisar e entender funções rotation_cost, get_position e find_target_in_a
// combinar as 3 para o algoritmo fazer as operações sozinho
// até a B ficar vazia, depois chamar a função de colocar o minimo da A no topo
// ----------------- FEITO

// ----------------- FAZER
// na real preciso iterar por todos os elementos na B e escolher o com
// menor custo, também preciso usar o RB na B, e otimizar com o RR caso
// também precise rotacionar a A, outra coisa que esqueci
// posso criar uma função para isso e guardar o elemento que tem o menor custo
// após achar ele coloco na posição correta
// ----------------- FAZER

// calcular custo da B para a A
// fazer a LIS na A

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

void	execute_movements(t_stack **stack_a, t_stack **stack_b, t_sheet sheet)
{
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

void	do_rotation(t_stack **stack_a, t_stack **stack_b)
{
	t_sheet	sheet;
	t_cost	cost;

	while (list_size(*stack_b) > 0)
	{
		sheet = find_cheapest_move(*stack_a, *stack_b, &cost);
		get_move_plan(&sheet, list_size(*stack_a), list_size(*stack_b));
		execute_movements(stack_a, stack_b, sheet);
		fn_push_a(stack_a, stack_b);
	}
	normalize_stack_a(stack_a);
	// printf("pos a: %d\npos b: %d\n", sheet.position_a, sheet.position_b);
	// printf("cheapest cost: %d\n", sheet.cheapest_cost);
	// printf("node_to_move: %d\n", sheet.target_node_to_move);
	// printf("target_in_a: %d\n", sheet.target_in_a);
	// printf("moves_a : %d\nmoves_b: %d\n", sheet.moves_a, sheet.moves_b);
	// printf("instruction_a: %s\n instruction_b: %s\n", sheet.instruction_a, sheet.instruction_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 2)
		stack_a = fill_stack(argv);
	else if (argc == 2)
		stack_a = fill_stack(ft_split(argv[1], ' '));
	// sort_list(&stack_a, &stack_b);
	clear_stack_a(&stack_a, &stack_b);
	// print_list(stack_a, stack_b);
	do_rotation(&stack_a, &stack_b);
	// print_list(stack_a, stack_b);
	// do_rotation(&stack_a, &stack_b);
	// print_list(stack_a, stack_b);
	// do_rotation(&stack_a, &stack_b);
	// sheet = find_cheapest_move(stack_a, stack_b);
	// do_rotation(&stack_a, &stack_b, sheet);
	// normalize_stack_a(&stack_a);
	// print_list(stack_a, stack_b);
	free_list(&stack_a, &stack_b);
	return (0);
}
