#include "ft_push_swap.h"

void ft_print_list(s_node *head)
{
    s_node    *current;

    current = head;
    if (!current)
        return ;
    while (current)
    {
        printf("    data is: %s     nmbr is: %d\n", current->data, current->nmbr);
        current = current->next;
    }
    return ;
}

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

void	ft_lstadd_front(s_node	**lst, s_node	*new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
