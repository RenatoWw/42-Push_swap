/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:03:16 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/10/07 15:58:42 by ranhaia-         ###   ########.fr       */
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
	if (*nptr == '-' || *nptr == '+')
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

	if (ft_strncmp(str[0], "./push_swap", 11) == 0)
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
			{
				ft_printf("Error\n");
				if (!(ft_strncmp(str[0], "./push_swap", 11) == 0))
					free_split(str);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_number(char *str)
{
	int	i;

	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (1);
	i = 0;
	while (str[i])
	{
		if (ft_atoi(str) == 0 && str[i] != '0')
			return (1);
		else if ((str[i] == '+' || str[i] == '-') && i != 0)
			return (1);
		else if (!(ft_isdigit(str[i])) && (str[i] != '-' && str[i] != '+'))
			return (1);
		else if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	**parse_string(int argc, char **str)
{
	int		i;
	int		flag;
	char	*trimmed;

	trimmed = ft_strtrim(str[1], " ");
	if (ft_strlen(trimmed) == 0)
	{
		free(trimmed);
		ft_error(str);
	}
	free(trimmed);
	i = 0;
	if (str[i] == NULL)
		ft_error(str);
	flag = 0;
	while (str[i])
		if (ft_strchr(str[i++], ' ') && argc > 2)
			flag = 1;
	if (flag == 1)
		ft_error(str);
	return (str);
}

void	parse_numbers(char **str)
{
	int	i;
	int	j;

	if (ft_strncmp(str[0], "./push_swap", 11) == 0)
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (check_number(str[i]) == 1)
				ft_error(str);
			j++;
		}
		i++;
	}
}
