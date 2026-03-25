/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:51:23 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/25 20:35:42 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_populate_node(t_node *i_dont_care, char *arg)
{
	i_dont_care = malloc(sizeof(t_node));
	if (!i_dont_care)
		return (NULL);
	i_dont_care->data = ft_strdup(arg);
	i_dont_care->nbr = ft_atol(i_dont_care->data);
	i_dont_care->next = NULL;
	return (i_dont_care);
}

t_node	*ft_map_args(char *argv[], int flg_argc)
{
	t_node	*head;
	t_node	*prev;
	t_node	*curr;
	int		i;

	i = 1 - flg_argc;
	curr = malloc(sizeof(t_node));
	if (!curr)
		return (NULL);
	curr->data = ft_strdup(argv[i]);
	curr->nbr = ft_atol(curr->data);
	curr->next = NULL;
	head = curr;
	prev = head;
	while (argv[++i])
	{
		curr = ft_populate_node(curr, argv[i]);
		if (!curr)
			return (NULL);
		prev->next = curr;
		prev = prev->next;
	}
	ft_order(&head);
	return (head);
}

void	ft_push_swap(t_node **head, t_node	**stack_b)
{
	if (!head || ft_lst_len(head) == 1)
		return ;
	if (ft_lst_len(head) == 2)
		ft_sort_2_digits(head);
	else if (ft_lst_len(head) == 3)
		ft_sort_3_digits(head);
	else if (ft_lst_len(head) == 4)
		ft_sort_4_digits(head, stack_b);
	else if (ft_lst_len(head) == 5)
		ft_sort_5_digits(head, stack_b);
	else
		ft_sort_all(head, stack_b);
	return ;
}

t_node	*map_argv(char *argv[], t_node **head)
{
	char	**out;
	t_node	*tmp;
	t_node	*curr;
	int		i;

	i = 1;
	out = ft_split(argv[1]);
	*head = ft_map_args(out, 1);
	ft_free_splited(out);
	while (argv[++i])
	{
		out = ft_split(argv[i]);
		tmp = ft_lstlast(*head);
		curr = ft_map_args(out, 1);
		if (!curr)
		{
			ft_free_lst(head);
			ft_free_splited(out);
			return (NULL);
		}
		tmp->next = curr;
		ft_free_splited(out);
	}
	ft_free_splited(out);
	return (*head);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_node	*head;
	t_node	*stack_b;

	i = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	head = map_argv(argv, &head);
	if (!head)
		return (ft_free_lst(&head));
	stack_b = NULL;
	ft_push_swap(&head, &stack_b);
	ft_print_lst(head);
	ft_free_lst(&head);
	return (0);
}
