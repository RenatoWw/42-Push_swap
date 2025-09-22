/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:38:09 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 15:47:09 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}		t_stack;

t_stack	*create_node(int content);
t_stack	*fill_stack(char **numbers);
void	parse_numbers(char **str);
void	free_split(char **line);
void	check_string(char **str);
void	insert_front(t_stack **head, int content);
void	insert_back(t_stack **head, int content);
void	insert_at_position(t_stack **head, int content, int position);
void	delete_first(t_stack **head);
void	delete_last(t_stack **head);
void	delete_at_position(t_stack **head, int position);
void	print_list(t_stack *head);
void	print_list_reversed(t_stack *head);
void	free_list(t_stack **head);
int		list_size(t_stack *head);
int		check_duplicates(char **str);
int		check_number(char *str);
long	ft_atol(const char *nptr);


#endif
