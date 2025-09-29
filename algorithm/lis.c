/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:28 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/29 17:48:07 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lis_length(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp2;
	int		size;
	int		*lis;

	size = list_size(*stack);
	lis = malloc(size * sizeof(int));
	temp2 = NULL;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	while (tail != NULL)
	{
		temp2 = tail;
		while (temp2 != NULL)
		{
			printf("temp: %d\n", temp2->content);
			temp2 = temp2->next;
		}
		printf("\n");
		tail = tail->next;
	}	
	return (1);
}
