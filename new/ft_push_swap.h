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
	int				nmbr;
	int				order;
} s_node;



/* ft_push_swap.c */
int		ft_validate_equal_args(int	argc, char *argv[]);
int		ft_validate_nmbr_args(int	argc, char *argv[]);
char	*ft_binary(int nmbr);
s_node	*ft_map_argvs(int argc, char *argv[]);
void	ft_free_lst(s_node **head);


/* Movements.c */
void	ft_rotate(s_node **head, char stack);
void	ft_push(s_node **from, s_node **to, char stack);
void	ft_swap(s_node **head, char stack);
void	ft_reverse_rotate(s_node **head, char stack);


/* More than 5 */
int		ft_validate_if_is_sorted(s_node **head);
void	ft_push_swap(s_node **stackA, s_node **stackB);
void	ft_order_argvs(s_node *head);


/* Less than five */
void	ft_sort_2_digits(s_node **head);
void	ft_sort_3_digits(s_node **head);


/* List */
void	ft_print_list(s_node *head);
void	ft_lstadd_front(s_node	**lst, s_node	*new);
s_node	*ft_lst_last(s_node	*head);


#endif
