#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <xlocale.h>

typedef struct t_node
{
	char			*data;
	char			*bin;
	struct t_node	*next;
} s_node;

void	ft_print_list(s_node *head);
s_node	*ft_lst_last(s_node	*head);
void	ft_rotate(s_node **head, char stack);
void	ft_push(s_node **from, s_node **to, char stack);

#endif