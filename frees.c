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

int	ft_free_lst(t_node **head)
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
	return (0);
}
