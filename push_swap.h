/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:38:09 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/06 16:40:26 by ranhaia-         ###   ########.fr       */
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
	int				lis_len;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*next_in_lis;
}		t_stack;

typedef struct s_sheet
{
	int		cheapest_cost;
	int		target_node_to_move;
	int		target_in_a;
	int		position_a;
	int		position_b;
}	t_sheet;

typedef struct s_cost
{
	int		target_in_a;
	int		position_b;
	int		cost_b;
	int		position_a;
	int		cost_a;
	int		total_cost;
	int		moves;
	char	*instruction;

}		t_cost;

void	parse_numbers(char **str);
void	free_split(char **line);
char	**parse_string(char **str);
int		check_duplicates(char **str);
int		check_number(char *str);
long	ft_atol(const char *nptr);

t_stack	*create_node(int content);
t_stack	*fill_stack(char **numbers);
void	insert_front(t_stack **head, int content);
void	insert_back(t_stack **head, int content);
void	insert_at_position(t_stack **head, int content, int position);
void	delete_first(t_stack **head);
void	delete_last(t_stack **head);
void	delete_at_position(t_stack **head, int position);
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

t_cost	*rotation_cost(int stack_size, t_cost *cost, char stack_id);
t_sheet	find_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void	three_elem_sort(t_stack **stack);
void	four_elem_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_list(t_stack **stack_a, t_stack **stack_b);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	normalize_stack_a(t_stack **stack);
void	rotate_calculator(t_stack **stack_a, t_cost cost);
void	clear_stack_a(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);
int		get_lis_length(t_stack **stack);
int		get_position(t_stack *stack, int value);
int		maximum_number_in_stack(t_stack *stack);
int		minimum_number_in_stack(t_stack *stack);
int		find_target_in_a(t_stack *stack_a, int *b_value);
int		find_target_in_b(t_stack *stack_b, int *a_value);

#endif
