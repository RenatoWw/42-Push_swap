/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 15:47:44 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	print_list(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (!temp)
	{
		printf("Empty list.\n");
		return ;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	printf("---\n A\n");
}

void	print_list_reversed(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (!temp)
	{
		printf("Empty list.\n");
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->content);
		temp = temp->prev;
	}
}

void	free_list(t_stack **head)
{
	t_stack	*temp;

	if (!(*head))
		return ;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}

int	list_size(t_stack *head)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
