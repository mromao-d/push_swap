/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:25:34 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/16 20:27:05 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **head, char stack)
{
	t_node	*tmp;

	if (!(*head) | !((*head)->next))
		return ;
	tmp = *head;
	*head = (*head)->next;
	ft_lstlast(*head)->next = tmp;
	tmp->next = NULL;
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}

void	ft_push(t_node **from, t_node **to, char stack)
{
	t_node	*tmp;

	if (from == NULL)
		return ;
	tmp = (*from);
	(*from) = (*from)->next;
	ft_lstadd_front(to, tmp);
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}

void	ft_swap(t_node **head, char stack)
{
	t_node	*tmp;

	if (head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	write(1, "s", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}

void	ft_reverse_rotate(t_node **head, char stack)
{
	t_node	*last;
	t_node	*prev;
	t_node	*current;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = NULL;
	prev = NULL;
	current = *head;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	last->next = *head;
	*head = last;
	prev->next = NULL;
	write(1, "rr", 2);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
