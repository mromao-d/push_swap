#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char		*data;
	int			nmbr;
	struct node	*next;
} Node;

void	ft_swap_sa(Node *head);
int	    ft_strlen(char	*str);
int 	ft_strcmp(const char *s1, const char *s2);
void	ft_print_list(Node *head);
int 	ft_count_nodes(Node *head);
char	*ft_atoi_for_validation(char	*str);
int 	ft_atoi_adapted(char *str);
Node	*ft_validate_nmbr(Node *head);
Node	*ft_map_argvs(int argc, char *argv[]);
void	ft_sort_shit(Node *head);
void	ft_push_swap(Node *head);
Node	*ft_rotate(Node *stack);
void	ft_rotate_test(Node	*stack);

#endif