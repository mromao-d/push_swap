/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:08:00 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/07 16:09:28 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi_adapted(char *str)
{
	int	i;
	int	n;
	int	nb;
	int	sign;

	sign = 1;
	i = -1;
	n = 0;
	nb = 0;
	if (str[0] == '-')
	{	
		sign = -1;
		i++;
	}
	while (str[++i])
	{
		n = str[i] - 48;
		nb = nb * 10 + n;
	}
	return(nb * sign);
}

char	*ft_atoi_for_validation(char	*str)
{
	int	n;
	int	nb;
	int	i;
	char	*fail;

	fail = malloc(sizeof(char) * 19);
	if (fail)
		return (NULL);
	fail = "Atoi says Fuck you";
	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = (str[i] - 48);
			nb = nb * 10 + n;
		}
		else
			return (fail);
	}
	free(fail);
	return (str);
}