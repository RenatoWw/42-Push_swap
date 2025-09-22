/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:29:33 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/06 14:51:32 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printer(char *str, int i, char flag)
{
	if (flag == 'x')
		while (i > 0)
			ft_putchar(ft_tolower(str[--i]));
	if (flag == 'X')
		while (i > 0)
			ft_putchar(ft_toupper(str[--i]));
}

int	ft_puthex(unsigned long num, char flag)
{
	char	*chr;
	char	str[40];
	int		remainder;
	int		i;
	int		count;

	chr = "ABCDEF";
	i = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num > 0)
	{
		remainder = num % 16;
		if (remainder >= 10 && remainder <= 15)
			str[i] = chr[remainder - 10];
		if (remainder >= 0 && remainder <= 9)
			str[i] = remainder + '0';
		i++;
		num /= 16;
	}
	count = i;
	str[i] = '\0';
	printer(str, i, flag);
	return (count);
}
