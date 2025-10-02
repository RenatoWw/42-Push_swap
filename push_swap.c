/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/01 21:23:35 by ranhaia-         ###   ########.fr       */
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
	sort_list(&stack_a, &stack_b);
	// fn_push_b(&stack_a, &stack_b);
	// fn_push_b(&stack_a, &stack_b);
	// fn_push_b(&stack_a, &stack_b);
	int	target;
	target = find_target_in_b(stack_b, &stack_a->content);
	// printf("target: %d\n", target);
	// print_list(stack_a, stack_b);
	free_list(&stack_a, &stack_b);
	return (0);
}
