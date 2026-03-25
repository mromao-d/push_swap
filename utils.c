/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:12:09 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/16 20:56:10 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *arg)
{
	int		i;
	int		sign;
	long	out;

	i = 0;
	sign = 1;
	out = 0;
	if (!arg)
		return (0);
	while (((arg[i] >= 9) && (arg[i] <= 13)) || (arg[i] == ' '))
		i++;
	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (arg[i] == '+')
		i++;
	while (ft_is_digit(arg[i]))
		out = out * 10 + arg[i++] - 48;
	return (out * sign);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = -1;
	j = 0;
	while (str[++i])
		;
	out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	while (j < i)
	{
		out[j] = str[j];
		j++;
	}
	out[j] = 0;
	return (out);
}

int	ft_val_nmbr_args(char *argv[], int start)
{
	int	i;
	int	j;

	i = start;
	if (!argv)
		return (2);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-') && (j == 0))
				j++;
			if (!ft_is_digit(argv[i][j]))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_val_eq_args(char *argv[], int start)
{
	int	i;
	int	j;

	i = start;
	if (!argv || !argv[start])
		return (3);
	while (*argv && argv[i])
	{
		if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) > 2147483647
			|| ft_atol(argv[i]) < -2147483648)
			return (3);
		j = i + 1;
		while (*argv && argv[j] != NULL)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}
