/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:35:49 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/25 20:34:46 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_splited(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	if (!split[0])
	{
		free(split);
		return ;
	}
	while (split[++i])
		free(split[i]);
	free(split);
	return ;
}

int	ft_free_lst(t_node **head, int print)
{
	t_node	*nxt;

	if (!head)
		return (0);
	while (*head)
	{
		nxt = (*head)->next;
		if ((*head)->data)
			free((*head)->data);
		free(*head);
		*head = nxt;
	}
	if (print)
		write(1, "Error\n", 6);
	return (0);
}

void	free_map_argv(char	**out, t_node **head)
{
	ft_free_lst(head, 0);
	ft_free_splited(out);
	return ;
}
