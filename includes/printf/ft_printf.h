/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:05:58 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/08/06 16:34:53 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int num);
int	ft_puthex(unsigned long num, char flag);
int	ft_putptr(unsigned long num);

#endif