/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:03:16 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/09/22 13:56:11 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		signal;
	long	num;

	signal = 1;
	num = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		num = (num * 10) + *nptr++ - '0';
	return (num * signal);
}

int	check_duplicates(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				printf("Error\n");
				// free_split(str);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(ft_atol(str[i]) > -2147483648 && ft_atol(str[i]) < 2147483647)
				|| (ft_atol(str[i]) > 2147483647
					|| ft_atol(str[i]) < -2147483648))
			{
				if (str[i][j] == '-' && ft_atoi(str[i]) != 0)
					break ;
				printf("Error\n");
				if (!(ft_strncmp(str[0], "./push_swap", 11) == 0))
					free_split(str);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
