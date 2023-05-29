#include "ft_push_swap.h"

s_node	*ft_lst_last(s_node	*head)
{
	if (!head)
		return (0);
	while (head)
	{
		if (!(head->next))
			break ;
		head = head->next;
	}
	return (head);
}

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

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (!(*to))
	{	
		*to = tmp;
		tmp->next = NULL;
	}
	else
	{	
		tmp->next = *to;
		*to = tmp;
	}
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return ;
}
