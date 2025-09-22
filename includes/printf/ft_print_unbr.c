/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:15:21 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/04 20:46:43 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	char	str[10];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (num == 0)
		count += ft_putchar('0');
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	while (i > 0)
		count += ft_putchar(str[--i]);
	return (count);
}
