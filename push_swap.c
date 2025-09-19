/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:50 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/18 19:49:19 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	*newlist;
	int		i;

	i = 0;
	newlist = NULL;
	while (i < 10)
		insert_back(&newlist, i++);
	printf("size: %d\n", list_size(newlist));
	printf("----------------LISTA ORIGINAL-----------------\n");
	print_list(newlist);
	printf("---------------------------------\n");
	delete_first(&newlist);
	print_list(newlist);
	printf("---------------------------------\n");
	delete_last(&newlist);
	print_list(newlist);
	printf("---------------------------------\n");
	free_list(newlist);
	return (0);
}
