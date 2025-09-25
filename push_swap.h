/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:38:09 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/25 14:33:52 by ranhaia-         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}		t_stack;

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
void	print_list_reversed(t_stack *head);
void	free_list(t_stack **stack_a, t_stack **stack_b);
int		list_size(t_stack *head);
void	fill_index(t_stack **stack);

void	fn_swap(t_stack **stack_a, t_stack **stack_b, char *instruction);
void	fn_swap_ss(t_stack **stack_a, t_stack **stack_b);
void	fn_push_a(t_stack **stack_a, t_stack **stack_b);
void	fn_push_b(t_stack **stack_a, t_stack **stack_b);
void	fn_rotate(t_stack **stack_a, t_stack **stack_b, char *instruction);
void	fn_reverse_rotate(t_stack **stck_a, t_stack **stck_b, char *operation);

void	three_elem_sort(t_stack **stack);
void	four_elem_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_list(t_stack **stack_a, t_stack **stack_b);

#endif
