/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/01 16:42:02 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = stack_a;
	temp_b = stack_b;
	while (1)
	{
		if (!temp_a)
			ft_printf(" %c", ' ');
		else
		{
			ft_printf(" %d", temp_a->content);
			temp_a = temp_a->next;
		}
		if (!temp_b)
			ft_printf("\t\t%c\n", ' ');
		else
		{
			ft_printf("\t\t%d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		if (!temp_a && !temp_b)
			break ;
	}
	ft_printf("---            ---\n A              B\n----------------------\n");
}

void	free_list(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_a) && !(*stack_b))
		return ;
	while (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	*stack_a = NULL;
	while (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
	*stack_b = NULL;
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
