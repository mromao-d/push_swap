/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:51:23 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/25 19:26:52 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 1 6 7 986 -1

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

int	ft_solve_two(char **argv, t_node **head, t_node	**stack_b)
{
	char	**out;
	int		i;

	out = ft_split(argv[1]);
	i = ft_val_nmbr_args(out, 0) + ft_val_eq_args(out, 0);
	if (i)
	{
		write(1, "Error\n", 6);
		ft_free_splited(out);
		return (1);
	}
	*head = ft_map_args(out, 1);
	*stack_b = NULL;
	ft_push_swap(head, stack_b);
	ft_free_splited(out);
	ft_free_lst(head);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_node	*head;
	t_node	*stack_b;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (argc == 2)
		return (ft_solve_two(argv, &head, &stack_b));
	i = ft_val_nmbr_args(argv, 1) + ft_val_eq_args(argv, 1);
	if (i)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	head = ft_map_args(argv, 0);
	stack_b = NULL;
	ft_push_swap(&head, &stack_b);
	ft_free_lst(&head);
	return (0);
}
