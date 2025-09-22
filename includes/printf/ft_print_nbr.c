/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:04:27 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/04 20:45:15 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	nb;
	char		str[12];
	int			i;
	int			count;

	nb = n;
	count = 0;
	if (nb == 0)
		count += ft_putchar('0');
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i > 0)
		count += ft_putchar(str[--i]);
	return (count);
}
