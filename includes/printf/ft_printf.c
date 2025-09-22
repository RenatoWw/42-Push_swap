/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 04:28:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/06 14:43:17 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conversion(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 'c')
		count += ft_putchar(va_arg(args, int));
	if (chr == 's')
		count += ft_putstr(va_arg(args, char *));
	if (chr == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	if (chr == 'd' || chr == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (chr == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	if (chr == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 'x');
	if (chr == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 'X');
	if (chr == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			count += check_conversion(str[++i], args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	unsigned int	num;
// 	void			*p;
// 	char *s2 = "Atirei o pau no gatis, per gatis num morreus.";

// 	p = &num;
// 	num = 4244334;
// 	printf("%d\n", ft_printf("|%s|%s|%s|%s|%s\n", " - ", "", "4", "", s2));
// 	printf("%d\n", printf("|%s|%s|%s|%s|%s\n", " - ", "", "4", "", s2));
// 	return (0);
// }
