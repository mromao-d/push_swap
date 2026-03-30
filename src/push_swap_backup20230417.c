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

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi_adapted(char *str)
{
	int	i;
	int	n;
	int	nb;
	int	sign;

	sign = 1;
	i = -1;
	n = 0;
	if (str[0] == '-')
	{	
		sign = -1;
		i++;
	}
	while (str[++i])
	{
		n = str[i] - 48;
		nb = nb * 10 + n;
	}
	return(nb * sign);
}

char	*ft_atoi_for_validation(char	*str)
{
	int	n;
	int	nb;
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = (str[i] - 48);
			nb = nb * 10 + n;
		}
		else
			return ("Atoi says Fuck you");
	}
	return (str);
}

node	*ft_validate_nmbr(node *head)
{
	node	*current;
	node	*error;

	error = malloc(sizeof(node));
	error->data = "The validation with Atoi says Fuck You!";
	error->next = NULL;
	current = head; 
	while (current)
	{
		current->data = ft_atoi_for_validation(current->data);
		if (ft_strcmp(current->data, "Atoi says Fuck you") == 0)
			return (error);
		current = current->next;
	}
	return (head);
}

char    *ft_binary(int   nmbr)
{
    int     i;
    char    *output;

    output = malloc(sizeof(char) * 33);
	if (!output)
		return (0);
    i = 31;
    while (i >= 0)
    {
        output[31 - i] = ((nmbr >> i) & 1 ) == 1 ? '1' : '0';
        i--;
    }
    output[32] = '\0';
    return (output);
}

void	ft_rank_argvs(node **head)
{
	node *tmp;
	node *current;

	current = *head;
	while (current)
	{
		tmp = *head;
		while (tmp)
		{
			if (current->nmbr > tmp->nmbr)
				current->rank++;
			tmp = tmp->next;
		}
		current = current->next;
	}
	return ;
}

void	ft_print_list(node *head)
{
	node	*current;
	
	current = head;
	if (!head)
	{
		printf("Nothing to print on print_list");
		return ;
	}
	if (ft_strcmp(current->data, "The validation with Atoi says Fuck You!") == 0)
	{	
		printf("%s \n", current->data);
		return ;
	}
	while (current)
	{
		printf("the number is: %i \n", current->nmbr);
		current = current->next;
	}
	return ;
}

void	ft_bin_argvs(node **head)
{
	node *tmp;

	tmp = *head;
	while (tmp)
	{
		tmp->bin = ft_binary(tmp->rank);
		tmp = tmp->next;
	}
	return ;
}

void	ft_order_argvs(node *head)
{
	int		i;
	node	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp->order = i;
		tmp = tmp->next;
		i++;
	}
	return ;
}

node	*ft_map_argvs(int argc, char *argv[])
{
	node	*temp;
	node	*current;
	node	*head;
	int		i;

	if (argc < 2)
		return (0);
	head = malloc(sizeof(node));
	head->data = argv[1];
	head->nmbr = ft_atoi_adapted(argv[1]);
	head->next = NULL;
	head->count_m = 0;
	head->rank = 0;
	current = head;
	i = 1;
	current = head;
	while (++i < argc)
	{
		temp = malloc(sizeof(node));
		if (!temp)
			return (NULL);
		temp->data = argv[i];
		temp->nmbr = ft_atoi_adapted(argv[i]);
		temp->rank = 0;
		temp->next = NULL;
		temp->count_m = 0;
		current->next = temp;
		current = temp;
	}
	ft_rank_argvs(&head);
	ft_bin_argvs(&head);
	ft_order_argvs(head);
	return (head);
}

int	ft_validate_if_is_sorted(node **head)
{
	node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->nmbr > tmp->next->nmbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

node	*ft_copy_node(node *head)
{
	node	*output;

	output = malloc(sizeof(node));
	if (!output)
		return (0);
	output->bin = head->bin;
	output->data = head->data;
	output->nmbr = head->nmbr;
	output->order = head->order;
	output->rank = head->rank;
	output->next = NULL;
	return (output);
}

node	*ft_copy_node_adpted(node *head)
{
	node	*output;

	output = malloc(sizeof(node));
	if (!output)
		return (0);
	output->bin = head->bin;
	output->data = head->data;
	output->nmbr = head->nmbr;
	output->order = head->order;
	output->rank = head->rank;
	output->next = head->next;
	return (output);
}

void	ft_delete_midle_node(node	**head, int order)
{
	int	i;
	node	*prev;
	node	*curr;

	i = 0;
	prev = NULL;
	curr = *head;
	if (!curr)
		return ;
	while (curr && i < order)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (prev && curr)
		prev->next = curr->next;
	else if (prev)
		prev->next = NULL;
	else
		(*head) = (*head)->next;
	if (curr)
		free(curr);
	return ;
}

void	ft_add_first_node(node **head, node *to_add)
{
	node	*tmp;

	if (!to_add)
		return ;
	tmp = ft_copy_node(to_add);
	if (*head)
		tmp->next = *head;
	/* else */
		*head = tmp;
	/* while (tmp)
		tmp = tmp->next; */
	/* free(to_add); */
	/* ft_delete_midle_node(head, 0); */
	return ;
}

void	ft_push(node **from, node **to, int order)
{
	int		i;
	node	*tmp;

	tmp = *from;
	i = 0;
	while (tmp && tmp->next != NULL && tmp->order < order)
	{	
		tmp = tmp->next;
		i++;
	}
	ft_add_first_node(to, tmp);
	/* ft_delete_midle_node(&tmp, 0); */
	ft_delete_midle_node(from, i);
	/* ft_order_argvs(*stackA); */
	return ;
}

void	ft_push_simple(node **from, node **to)
{
	node	*tmp;

	tmp = *from;
	if (!tmp)
		return ;
	/* (*stackA)->count_m++; */
	if (!*to)
		*to = ft_copy_node(*from);
	else
		ft_add_first_node(to, ft_copy_node(tmp));
	*from = (*from)->next;
	/* ft_add_move(stackA);
	ft_add_move(stackB); */
	/* tmp->next = NULL; */
	free(tmp);
	return ;
}

void	ft_push_swap(node **stackA, node **stackB)
{
	node	*tmp;
	/* node	*tmpb; */
	int		i;
	int		pos;
	/* int		val; */

	tmp = *stackA;
	i = 0;
	pos = 31;
	/* val = ft_validate_if_is_sorted(stackA); */
	while (/* val != 1 &&  */pos > 30)
	{
		/* tmp = *stackA; */
		if (!tmp)
			return ;
		while (tmp)
		{
			((tmp->bin)[pos] == '0') ? ft_push(stackA, stackB, i) : 0;
			i++;
			tmp = tmp->next;
		}
		/* tmpb = *stackB; */
		/* if (!tmpb)
			return ;
		while (tmpb)
		{
			ft_push_simple(stackB, stackA);
			tmpb = tmpb->next;
		} */
		pos--;
		/* val = ft_validate_if_is_sorted(stackA); */
		/* ft_order_argvs(*stackA); */
	}
	return ;
}

int	main(int argc, char *argv[])
{
	node	*stackA;
	node	*stackB;
	/* min_max	a; */

	/* stackB = malloc(sizeof(node));
	stackB = NULL; */
	/* stackB->data = "2312";
	stackB->nmbr = 2312; */
	stackA = ft_map_argvs(argc, argv);
	/* stackA = ft_validate_nmbr(stackA); */
	/* ft_push(&stackA, &stackB);
	ft_push(&stackA, &stackB); */
	/* if (strcmp(head->data, "The validation with Atoi says Fuck You!") == 0)
	{
		ft_print_list(head);
		return (0);
	} */
	/* a = ft_save_min_max(head);
	printf("\n\n %d \n\n", a.min); */
	/* ft_swap_sa(head); */
	/* ft_sort_shit(head); */
	/* ft_push_test(head, stackB, head); */
	/* head = ft_rotate(head); */
	/* printf("\nthe value is: %d \n\n", ft_find_max(head)); */
	/* ft_reverse_rotate(&head); */
	/* printf("\n\n asds%d \n\n", ft_atoi_adapted("42")); */
	
	/* if (argc == 3)
		ft_sort_2_digits(&head, argc, *argv);
	else if (argc == 4)
		ft_sort_3_digits(&head, argc);
	else if (argc < 6)
		ft_sort_6_digits(&head, &stackB, argc, *argv); */
	
	/* ft_sort_6_digits(&head, &stackB, argc, *argv); */

	ft_push_swap(&stackA, &stackB);
	/* ft_rotate(&head); */
	/* ft_push(&head, &stackB);
	ft_push(&head, &stackB); */
	/* ft_print_list(stackA); */
	/* printf("\n\n  %d  \n\n", head->count_m); */
	/* ft_print_list(stackB); */
	/* printf("\n\n");
	ft_print_list(stackB); */
	while (stackA)
	{
		printf("the argvA is %d: 		and the rank is: %d		and the bin is: %s		and the order is: %d\n", stackA->nmbr, stackA->rank, stackA->bin, stackA->order);
		stackA = stackA->next;
	}
	printf("\n\n");
	/* ft_add_first_node(&stackB, stackA); */
	while (stackB)
	{
		printf("	the argvB is %d: 		and the rank is: %d		and the bin is: %s		and the order is: %d\n", stackB->nmbr, stackB->rank, stackB->bin, stackB->order);
		stackB = stackB->next;
	}
	/* ft_push_swap(&stackA, &stackB); */
	return (0);
}


