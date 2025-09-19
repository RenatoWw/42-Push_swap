/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:48:27 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/18 19:52:35 by ranhaia-         ###   ########.fr       */
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
