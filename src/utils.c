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

int	ft_val_nmbr_args(t_node **head)
{
	t_node	*curr;
	int	j;

	curr = *head;
	if (!curr || !curr->data)
		return (2);
	while (curr && curr->data)
	{
		j = 0;
		while (curr->data[j])
		{
			if ((curr->data[j] == '-') && (j == 0))
				j++;
			if (!ft_is_digit(curr->data[j]))
				return (2);
			j++;
		}
		curr = curr->next;
	}
	return (0);
}

int	ft_val_eq_args(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	if (!curr || !curr->data)
		return (3);
	while (curr && curr->data)
	{
		if (ft_strlen(curr->data) > 11 || ft_atol(curr->data) > 2147483647
			|| ft_atol(curr->data) < -2147483648)
			return (3);
		tmp = curr->next;
		while (tmp && tmp->data != NULL)
		{
			if (ft_atol(tmp->data) == ft_atol(curr->data))
				return (3);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (0);
}
