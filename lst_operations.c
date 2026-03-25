/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:52:21 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/24 19:49:01 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_print_lst(t_node	*head)
// {
// 	t_node	*curr;

// 	curr = head;
// 	if (!curr) {
// 		perror("no curr\n") ;
// 		exit(1);
// 	}
// 	while (curr) {
// 		printf("data is %s		nmbr is %d		
// 			and order is %i\n", curr->data, curr->nbr, curr->order);
// 		curr = curr->next;
// 	}
// 	return ;
// }

t_node	*ft_lstlast(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

// validates if there are numbers to be sent to stack B
int	ft_lst_len(t_node **stackA)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stackA;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// orders the received numbers
void	ft_order(t_node **head)
{
	t_node	*tmp;
	t_node	*curr;

	tmp = *head;
	curr = *head;
	while (curr)
	{
		curr->order = 0;
		while (tmp)
		{
			if (tmp->nbr < curr->nbr)
				curr->order += 1;
			tmp = tmp->next;
		}
		tmp = *head;
		curr = curr->next;
	}
}
