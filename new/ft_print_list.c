#include "ft_push_swap.h"

void ft_print_list(s_node *head)
{
    s_node    *current;

    current = head;
    if (!current)
        return ;
    while (current)
    {
        printf("%s\n", current->data);
        current = current->next;
    }
    return ;
}
