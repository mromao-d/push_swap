/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:53:29 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/07 18:47:18 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*ft_copy_node(node *head)
{
	node	*output;

	output = malloc(sizeof(*output));
	if (!output)
		return (NULL);
	output->bin = head->bin;
	output->data = head->data;
	output->nmbr = head->nmbr;
	output->order = head->order;
	output->rank = head->rank;
	output->next = NULL;
	return (output);
}

node	*ft_copy_node_adpted(node *head)
{
	node	*output;

	output = malloc(sizeof(*output));
	if (!output)
		return (0);
	output->bin = head->bin;
	output->data = head->data;
	output->nmbr = head->nmbr;
	output->order = head->order;
	output->rank = head->rank;
	output->next = head->next;
	return (output);
}

void	ft_free_lst(node **head)
{
	node	*nxt;

	if (!head)
		return ;
	while (*head)
	{
		nxt = (*head)->next;
		if ((*head)->bin)
			free((*head)->bin);
		/* if ((*head)->data)
			free((*head)->data); */
		/* free((*head)->); */
		free(*head);
		(*head) = nxt;
	}
	return ;
}

void	ft_delete_midle_node(node	**head, int order)

{
	int	i;
	node	*prev;
	node	*curr;

	if (*head == NULL)
		return ;
	i = 0;
	prev = NULL;
	curr = *head;
	if (!curr)
		return ;
	while (curr && i < order)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	/* ft_free_lst(&curr); */
	if (curr == NULL)
		return ;
	if (prev && curr)
		prev->next = curr->next;
	else if (prev != NULL)
		prev->next = curr->next;
	else if (prev)
		prev->next = NULL;
	else
		(*head) = curr->next;
	/* if (curr)
	{
		free (curr);
	} */
	free (curr);
	return ;
}

void	ft_add_first_node(node **head, node *to_add)
{
	node	*tmp;
	node	*out;

	if (!to_add)
		return ;
	if (!(*head))
	{	
		*head = ft_copy_node(to_add);
		return ;
	}
	tmp = ft_copy_node(to_add);
	if (!tmp)
		return ;
	out = tmp;
	/* if (*head) */
	tmp->next = *head;
	/* else */
	/* while (tmp)
		tmp = tmp->next; */
	/* free(*head); */
	*head = tmp;
	/* while (tmp)
		tmp = tmp->next; */
	/* free(to_add); */
	/* ft_delete_midle_node(head, 0); */
	return ;
}

void	ft_push(node **from, node **to, int order, char	stack)
{
	int		i;
	node	*tmp;

	if (!*from /* || !*to */)
		return ;
	tmp = *from;
	/* if (!tmp)
		return ; */
	i = 0;
	while (tmp && tmp->next != NULL && tmp->order < order)
	{	
		tmp = tmp->next;
		i++;
	}
	ft_add_first_node(to, tmp);
	/* ft_delete_midle_node(&tmp, 0); */
	ft_delete_midle_node(from, i);
	/* ft_order_argvs(*stackA); */
	if (stack)
		printf("p%c\n", stack);
	return ;
}

void	ft_push_simple(node **from, node **to, char	stack)
{
	node	*tmp;

	if (!from)
		return ;
	tmp = *from;
	if (!tmp)
		return ;
	/* (*stackA)->count_m++; */
	if (!*to)
		*to = ft_copy_node(*from);
	else
		/* ft_add_first_node(to, ft_copy_node(tmp)); */
		ft_add_first_node(to, tmp);
	if (tmp)
		free(tmp);
	*from = (*from)->next;
	/* ft_add_move(stackA);
	ft_add_move(stackB); */
	/* tmp->next = NULL; */
	printf("p%c\n", stack);
	return ;
}

void	ft_rotate(node **head, char	stack)
{
	node	*tmp;
	node	*del;
	node	*curr;

	tmp = ft_copy_node(*head);
	if (!tmp)
		return ;
	tmp->next = NULL;
	/* (*stackA)->count_m++; */
	del = *head;
	(*head) = (*head)->next;
	free(del);
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
	printf("r%c\n", stack);
	return ;
}
