/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:46:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/23 17:03:31 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_front(t_stack **head, int content)
{
	t_stack	*newnode;

	newnode = create_node(content);
	if (!(*head))
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*head = newnode;
		return ;
	}
	newnode->next = *head;
	newnode->prev = NULL;
	(*head)->prev = newnode;
	*head = newnode;
}

void	insert_back(t_stack **head, int content)
{
	t_stack	*newnode;
	t_stack	*temp;

	newnode = create_node(content);
	if (!(*head))
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	newnode->next = NULL;
	newnode->prev = temp;
}

void	insert_at_position(t_stack **head, int content, int position)
{
	t_stack	*newnode;
	t_stack	*temp;
	int		size;

	size = list_size(*head);
	if (position > size || position < 1)
		return ;
	else if (position == 1)
		insert_front(head, content);
	else if (position == size)
		insert_back(head, content);
	else
	{
		newnode = create_node(content);
		temp = *head;
		while (--position)
			temp = temp->next;
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
	}
}
