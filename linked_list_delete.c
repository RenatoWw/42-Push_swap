/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:48:27 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 15:55:07 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_first(t_stack **head)
{
	t_stack	*temp;
	int		size;

	size = list_size(*head);
	if (!(*head))
		return ;
	else if (size == 1)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		(*head)->prev = NULL;
	}
}

void	delete_last(t_stack **head)
{
	t_stack	*temp;

	if (!(*head))
		return ;
	temp = *head;
	if (temp->next == NULL)
	{
		*head = NULL;
		free(*head);
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
}

void	delete_at_position(t_stack **head, int position)
{
	t_stack	*temp;
	int		size;

	if (*head == NULL || head == NULL)
		return ;
	size = list_size(*head);
	if (position < 1 || position > size)
		return ;
	else if (position == 1)
		delete_first(head);
	else if (position == size)
		delete_last(head);
	else
	{
		temp = *head;
		while (--position)
			temp = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
}
