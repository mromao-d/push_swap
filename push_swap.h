/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:49:20 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/25 20:35:01 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// I need the order to ensure that the order is correct
// (for negatives and huge numbers)
typedef struct s_node
{
	char			*data;
	struct s_node	*next;
	int				nbr;
	int				order;
}	t_node;

// lst_operations
// void	ft_print_lst(t_node	*head);
t_node	*ft_lstlast(t_node *head);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lst_len(t_node **stackA);
void	ft_order(t_node **head);

// movements
void	ft_rotate(t_node **head, char stack);
void	ft_swap(t_node **head, char stack);
void	ft_reverse_rotate(t_node **head, char stack);
void	ft_push(t_node **from, t_node **to, char stack);

// sorts
void	ft_sort_2_digits(t_node **head);
void	ft_sort_3_digits(t_node **head);
void	ft_sort_4_digits(t_node **stackA, t_node **stackB);
void	ft_sort_5_digits(t_node **stackA, t_node **stackB);
void	ft_sort_all(t_node **stackA, t_node **stackB);

// split
char	**ft_split(char *argv);

// utils
char	*ft_strdup(char *str);
long	ft_atol(const char *arg);
int		ft_is_digit(const char c);
int		ft_val_eq_args(char *argv[], int start);
int		ft_val_nmbr_args(char *argv[], int start);

// sorts_utils
int		ft_find_lowest(t_node *head);
int		ft_validate_sorted(t_node **head);
int		ft_validate_bin(t_node **stackA, int pos);
int		ft_strlen(char *str);

// frees
void	ft_free_splited(char **split);
int		ft_free_lst(t_node **head);
