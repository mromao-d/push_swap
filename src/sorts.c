/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:05:18 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/24 18:58:45 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2_digits(t_node **head)
{
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	second = (*head)->next;
	if (second->nbr > (*head)->nbr)
		return ;
	ft_rotate(head, 'a');
	return ;
}

void	ft_sort_3_digits(t_node **head)
{
	if ((*head)->nbr < (*head)->next->nbr
		&& (*head)->next->nbr < (*head)->next->next->nbr)
		return ;
	else if ((*head)->nbr > (*head)->next->nbr
		&& (*head)->nbr < (*head)->next->next->nbr)
		return (ft_swap(head, 'a'));
	else if ((*head)->nbr > (*head)->next->nbr
		&& (*head)->next->nbr > (*head)->next->next->nbr)
	{
		ft_swap(head, 'a');
		ft_reverse_rotate(head, 'a');
	}
	else if ((*head)->nbr > (*head)->next->next->nbr
		&& (*head)->next->next->nbr > (*head)->next->nbr)
		return (ft_rotate(head, 'a'));
	else if ((*head)->next->nbr > (*head)->next->next->nbr
		&& (*head)->next->next->nbr > (*head)->nbr)
	{
		ft_swap(head, 'a');
		ft_rotate(head, 'a');
	}
	else if ((*head)->next->nbr > (*head)->nbr
		&& (*head)->nbr > (*head)->next->next->nbr)
		return (ft_reverse_rotate(head, 'a'));
	return ;
}

void	ft_sort_4_digits(t_node **stackA, t_node **stackB)
{
	int	min_pos;

	min_pos = ft_find_lowest(*stackA);
	if (min_pos < 0)
		while (0 > min_pos++)
			ft_reverse_rotate(stackA, 'a');
	else if (min_pos > 0)
		while (0 < min_pos--)
			ft_rotate(stackA, 'a');
	ft_push(stackA, stackB, 'b');
	ft_sort_3_digits(stackA);
	ft_push(stackB, stackA, 'a');
	return ;
}

void	ft_sort_5_digits(t_node **stackA, t_node **stackB)
{
	int	min_pos;

	min_pos = ft_find_lowest(*stackA);
	if (min_pos < 0)
		while (0 > min_pos++)
			ft_reverse_rotate(stackA, 'a');
	else if (min_pos > 0)
		while (0 < min_pos--)
			ft_rotate(stackA, 'a');
	ft_push(stackA, stackB, 'b');
	ft_sort_4_digits(stackA, stackB);
	ft_push(stackB, stackA, 'a');
	return ;
}

void	ft_sort_all(t_node **stackA, t_node **stackB)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_lst_len(stackA);
	while (!ft_validate_sorted(stackA))
	{
		j = 0;
		while (j < size)
		{
			if (((*stackA)->order >> i) & 1)
				ft_rotate(stackA, 'a');
			else
				ft_push(stackA, stackB, 'b');
			j++;
		}
		while (*stackB)
			ft_push(stackB, stackA, 'a');
		i++;
	}
	return ;
}
