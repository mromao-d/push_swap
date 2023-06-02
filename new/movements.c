#include "ft_push_swap.h"

void	ft_rotate(s_node **head, char stack)
{
	s_node *tmp;

	if (!(*head) || !((*head)->next))
		return ;
	tmp = *head;
	*head = (*head)->next;
	ft_lst_last(*head)->next = tmp;
	tmp->next = NULL;
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}

void	ft_push(s_node **from, s_node **to, char	stack)
{
	s_node *tmp;

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

void	ft_swap(s_node **head, char stack)
{
	s_node	*tmp;

	if (head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next->next;
	(*head)->next = tmp;
	write(1, "s", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}

void ft_reverse_rotate(s_node **head, char stack)
{
	s_node *last;
	s_node *prev;
	s_node *current;

	if (*head == NULL || (*head)->next == NULL)
		return;
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
