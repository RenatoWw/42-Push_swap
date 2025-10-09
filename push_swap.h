/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:38:09 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/09 17:37:21 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft/libft.h"
# include "includes/printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				is_in_lis;
	struct s_stack	*prev;
	struct s_stack	*next;
}		t_stack;

typedef struct s_sheet
{
	int		cheapest_cost;
	int		target_node_to_move;
	int		target_in_a;
	int		target_in_b;
	int		position_a;
	int		position_b;
	int		moves_a;
	int		moves_b;
	char	*instruction_a;
	char	*instruction_b;
}	t_sheet;

typedef struct s_cost
{
	int		target_in_a;
	int		target_in_b;
	int		position_b;
	int		cost_b;
	int		position_a;
	int		cost_a;
	int		total_cost;
	int		moves;
	char	*instruction;
}		t_cost;

typedef struct s_lis
{
	int	last_n_found;
	int	max_pos;
	int	max_lis;
}		t_lis;

void	parse_numbers(char **str);
void	free_split(char **line);
char	**parse_string(int argc, char **str);
int		check_duplicates(char **str);
int		check_number(char *str);
long	ft_atol(const char *nptr);
void	ft_error(char **str);

t_stack	*create_node(int content);
t_stack	*fill_stack(char **numbers);
void	insert_front(t_stack **head, int content);
void	insert_back(t_stack **head, int content);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void	free_list(t_stack **stack_a, t_stack **stack_b);
void	fill_index(t_stack **stack);
int		list_size(t_stack *head);

void	fn_swap(t_stack **stack_a, t_stack **stack_b, char *instruction);
void	fn_swap_ss(t_stack **stack_a, t_stack **stack_b);
void	fn_push_a(t_stack **stack_a, t_stack **stack_b);
void	fn_push_b(t_stack **stack_a, t_stack **stack_b);
void	fn_rotate(t_stack **stack_a, t_stack **stack_b, char *instruction);
void	fn_reverse_rotate(t_stack **stck_a, t_stack **stck_b, char *operation);

t_cost	*rotation_cost(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
t_sheet	find_cheapest_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
void	stack_to_rotate(t_cost *cost, char stack_id, int below);
void	three_elem_sort(t_stack **stack);
void	four_elem_sort(t_stack **stack_a, t_stack **stack_b);
void	five_elem_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_list(t_stack **stack_a, t_stack **stack_b);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	normalize_stack_a(t_stack **stack);
void	clear_stack_a(t_stack **stack_a, t_stack **stack_b);
void	execute_movements(t_stack **stack_a, t_stack **stack_b, t_sheet sheet);
void	get_move_plan(t_sheet *sheet, int size_a, int size_b);
void	double_movement(t_stack **stack_a, t_stack **stack_b, t_sheet *sheet);
int		is_sorted(t_stack **stack);
int		get_position(t_stack *stack, int value);
int		maximum_number_in_stack(t_stack *stack);
int		minimum_number_in_stack(t_stack *stack);
int		find_target_in_a(t_stack *stack_a, int *b_value);
int		find_target_in_b(t_stack *stack_b, int *a_value);

int		*calculate_lis(t_stack *stack);
int		*fill_lis_arr(int *lis_arr, int *aux_arr, int size);
int		*create_aux_arr(t_stack *stack);
int		*create_index_arr(int *aux_arr, int *lis_arr, int size);
int		*revert_arr(int *idx_arr, int size);
int		get_max_position(int *lis_arr, int max_lis, int size);
int		get_max_lis(int *lis_arr, int size);
void	set_lis_to_zero(t_stack *stack_a);
void	assign_lis(t_stack *stack_a);

#endif
