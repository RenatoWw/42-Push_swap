/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:38:09 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/16 18:01:38 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	insert_front(t_stack **head, int content);
void	insert_back(t_stack **head, int content);
void	insert_at_position(t_stack **head, int content, int position);
void	delete_first(t_stack **head);
void	delete_last(t_stack **head);
void	print_list(t_stack *head);
void	free_list(t_stack *head);
int		list_size(t_stack *head);



#endif
