#include "ft_push_swap.h"

void	ft_sort_2_digits(s_node **head)
{
	if ((*head)->nmbr > (*head)->next->nmbr)
		ft_rotate(head, 'a');
	return ;
}

void	ft_sort_3_digits(s_node **head)
{
	if ((*head)->nmbr < (*head)->next->nmbr && (*head)->next->nmbr < (*head)->next->next->nmbr)
		return ;
	else if ((*head)->nmbr > (*head)->next->nmbr && (*head)->nmbr < (*head)->next->next->nmbr)
		return (ft_swap(*head, 'a'));
	else if ((*head)->nmbr > (*head)->next->nmbr && (*head)->next->nmbr > (*head)->next->next->nmbr)
	{
		ft_swap(head, 'a');
		ft_reverse_rotate(head, 'a');
	}
	else if ((*head)->nmbr > (*head)->next->next->nmbr && (*head)->next->next->nmbr > (*head)->next->nmbr)
		return (ft_rotate(head, 'a'));
	else if ((*head)->next->nmbr > (*head)->next->next->nmbr && (*head)->next->next->nmbr > (*head)->nmbr)
	{
		ft_swap(head, 'a');
		ft_rotate(head, 'a');
	}
	else if ((*head)->next->nmbr > (*head)->nmbr && (*head)->nmbr > (*head)->next->next->nmbr)
		return (ft_reverse_rotate(head, 'a'));
	return ;
}
