/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:27:48 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/16 20:56:16 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds the lowest number position
// returns positive if lowest is closer to start 
// returns negative if it is closer to the end of the list
int	ft_find_lowest(t_node *head)
{
	int		len;
	int		min;
	int		min_pos;
	t_node	*tmp;

	if (!head)
		return (0);
	tmp = head;
	min = 0;
	len = 0;
	min_pos = 0;
	min = tmp->nbr;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->next->nbr < min)
		{
			min = tmp->next->nbr;
			min_pos = len + 1;
		}
		len++;
		tmp = tmp->next;
	}
	if (min_pos <= len / 2)
		return (min_pos);
	return (-(len - min_pos));
}

// validate if it is sorted.
// returns 1 if sorted
// returns 0 if not sorted
int	ft_validate_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp && tmp->next)
	{
		if (tmp->next->order < tmp->order)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// validates if there are numbers to be sent to stack B
int	ft_validate_bin(t_node **stackA, int pos)
{
	t_node	*tmp;

	if (!stackA || !*stackA)
		return (0);
	tmp = *stackA;
	while (tmp)
	{
		if (!((tmp->order >> pos) & 1))
		{
			printf("have to push %s in order %i\n", tmp->data, tmp->order);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
