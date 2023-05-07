/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:01 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/07 16:59:45 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

typedef struct Node
{
	char		*data;
	int			nmbr;
	int			rank;
	struct Node	*next;
	int			count_m;
	char		*bin;
	int			order;
} node;

node	*ft_copy_node(node *head);
node	*ft_copy_node_adpted(node *head);
void	ft_free_lst(node **head);
void	ft_delete_midle_node(node	**head, int order);
void	ft_add_first_node(node **head, node *to_add);
void	ft_push(node **from, node **to, int order, char	stack);
void	ft_push_simple(node **from, node **to, char	stack);
void	ft_rotate(node **head, char	stack);

int     ft_strlen(char	*str);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_atoi_adapted(char *str);
char	*ft_atoi_for_validation(char	*str);

#endif