#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	Min_max {
	int	min;
	int	second_min;
	int	min_pos;
	int	second_min_pos;
	int	max;
	int	second_max;
	int	max_pos;
	int	second_max_pos;
	int	operations;
	int	count_moves;
} min_max;

typedef struct Node {
	char		*data;
	int			nmbr;
	int			rank;
	struct Node	*next;
	int			count_m;
	char		*bin;
	int			order;
} node;

void	ft_swap_sa(node *head);
int	    ft_strlen(char	*str);
int 	ft_strcmp(const char *s1, const char *s2);
void	ft_print_list(node *head);
int 	ft_count_nodes(node *head);
char	*ft_atoi_for_validation(char	*str);
int 	ft_atoi_adapted(char *str);
node	*ft_validate_nmbr(node *head);
node	*ft_map_argvs(int argc, char *argv[]);
void	ft_sort_shit(node *head);
void	ft_push_swap(node *head);
void	ft_reverse_rotate(node **stack);
void	ft_push(node **stackA, node **stackB);
/* void	ft_rotate_test(node	*stack); */
void	ft_rotate(node	**stack);
void	ft_push_test(node *stackA, node *stackB);
void	ft_sort_3_digits(node **head, int argc);
void	ft_sort_6_digits(node **stackA, node **stackB, int argc/* , char argv[] */);
void	ft_add_first_node(node **head, node	*copy);
char    *ft_binary(int nmbr);
void	ft_push_val(node **stackA, node *stackB, int	order);
node	*ft_copy_node(node	*head);
void	ft_add_move(node **head);
void	ft_order_argvs(node *head);

#endif