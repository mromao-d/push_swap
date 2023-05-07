#include "ft_push_swap.h"

min_max	ft_save_min_max(node *head, int argc)
{
	node	*tmp;
	int		i;
	min_max	save;

	i = 1;
	tmp = head;
	save.max = tmp->nmbr;
	save.max_pos = i;
	save.min = tmp->nmbr;
	save.min_pos = i;
	while (tmp)
	{
		tmp->nmbr > save.max ? (save.max = tmp->nmbr, save.max_pos = i) : 0;
		tmp->nmbr < save.min ? (save.min = tmp->nmbr, save.min_pos = i) : 0;
		i++;
		tmp = tmp->next;
	}
	if (argc > 3)
	{
		i = 1;
		tmp = head;
		save.second_max = tmp->nmbr;
		save.second_max_pos = i;
		save.second_min_pos = tmp->nmbr;
		save.second_min_pos = i;
		while (tmp)
		{
			(tmp->nmbr > save.second_max && tmp->nmbr < save.max) ? (save.second_max = tmp->nmbr, save.second_max_pos = i) : 0;
			(tmp->nmbr < save.second_min && tmp->nmbr > save.min) ? (save.second_min = tmp->nmbr, save.second_min_pos = i) : 0;
			i++;
			tmp = tmp->next;
		}
	}
	return (save);
}

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

int	ft_count_nodes(node *head)
{
	int		i;
	node	*current;

	i = 0;
	current = head;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
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

node	*ft_map_argvs(int argc, char *argv[])
{
	node	*temp;
	node	*current;
	node	*head;
	int		i;

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

void	ft_sort_shit(node *head)
{
	node	*current;
	
	current = head;
	while (current->next != NULL)
	{
		if (current->nmbr > current->next->nmbr)
		{	
			ft_swap_sa(current);
			current = head;
		}
		else
			current = current->next;
	}
}

int	ft_find_max(node	*stack)
{
	int	i;

	i = stack->nmbr;
	while (stack)
	{
		if (i < stack->nmbr)
			i = stack->nmbr;
		stack = stack->next;
	}
	return (i);
}

void	ft_sort_2_digits(node **head, int argc/* , char argv[] */)
{
	if (argc != 3)
	{
		printf("Merda no sort 2");
		return ;
	}
	(*head)->nmbr > (*head)->next->nmbr ? ft_swap_sa(*head) : 0;
	return ;
}

void	ft_sort_3_digits(node **head, int argc)
{
	node	array[argc - 1];
	node	*temp;
	int		i;

	i = 0;
	temp = *head;
	if (ft_count_nodes(*head) < 3)
	{
		printf("Less than 3 args entered ft_sort_3_digits\n");
		return ;
	}
	while (i < 3)
	{
		array[i].nmbr = temp->nmbr;
		temp = temp->next;
		/* printf("nmbr %i is %i\n", i, array[i].nmbr); */
		i++;
	}
	if (array[0].nmbr < array[1].nmbr && array[1].nmbr < array[2].nmbr)
		return ;
	else if (array[0].nmbr > array[1].nmbr && array[0].nmbr < array[2].nmbr)
		return (ft_swap_sa(*head));
	else if (array[0].nmbr > array[1].nmbr && array[1].nmbr > array[2].nmbr)
	{
		ft_swap_sa(*head);
		ft_reverse_rotate(head);
	}
	else if (array[0].nmbr > array[2].nmbr && array[2].nmbr > array[1].nmbr)
		return (ft_rotate(head));
	else if (array[1].nmbr > array[2].nmbr && array[2].nmbr > array[0].nmbr)
	{
		ft_swap_sa(*head);
		ft_rotate(head);
	}
	else if (array[1].nmbr > array[0].nmbr && array[0].nmbr > array[2].nmbr)
		return (ft_reverse_rotate(head));
	return ;
}

int	ft_max_argv(node	*head)
{
	node *tmp;
	int		i;

	tmp = head;
	i = tmp->nmbr;
	while (tmp)
	{
		if (tmp->nmbr > i)
			i = tmp->nmbr;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_min_argv(node	*head)
{
	node *tmp;
	int		i;

	tmp = head;
	i = tmp->nmbr;
	while (tmp)
	{
		if (tmp->nmbr < i)
			i = tmp->nmbr;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_validate_if_is_sorted(node **head)
{
	node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->nmbr > tmp->next->nmbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_6_digits(node **stackA, node **stackB, int argc/* , char argv[] */)
{
	min_max	save;
	int		i;
	int		operations;
	
	if (ft_validate_if_is_sorted(stackA) == 0)
		return ;
	operations = 0;
	while (ft_count_nodes(*stackA) > 3)
	{
		i = 0;
		save = ft_save_min_max(*stackA, argc);
		if (save.min_pos > argc / 2)
			while (++i < save.min_pos)
				ft_rotate(stackA);
		else
			while (++i > argc)
				ft_reverse_rotate(stackA);
		ft_push(stackA, stackB);
		operations++;
	}
	ft_sort_3_digits(stackA, argc);
	/* printf("\n\n\n");
	ft_print_list(*stackB);
	printf("\n\n\n"); */
	while (operations > 0)
	{
		ft_push(stackB, stackA);
		operations--;
	}	
}

void	ft_push_val(node **stackA, node *stackB, int	order)
{
	int	i;
	node	*tmp;

	i = 0;
	tmp = *stackA;
	if (!tmp)
		return ;
	while (tmp && i < order)
	{
		tmp = tmp->next;
		i++;
	}
	if (!stackB)
		stackB = ft_copy_node(*stackA);
	else
		ft_add_first_node(&stackB, ft_copy_node(tmp));
	/* if (tmp->next->next)
		tmp->next = tmp->next->next;
	else if (tmp->next)
		tmp->next = NULL;
	else
		tmp->next = NULL; */
	/* free (tmp); */
	return ;
}

void	ft_get_next_line (node **stackA, node **stackB)
{
	int		i;
	node	*tmp;

	i = 31;
	tmp = *stackA;
	while (tmp)
	{
		(tmp->bin)[i] == '0' ? (tmp->rank = 9999, ft_push_val(&tmp, *stackB, 31 - i)) : 0;
		tmp = tmp->next;
		/* ft_order_argvs(*stackA); */
		/* i-- */
	}
	return ;
}

int	main(int argc, char *argv[])
{
	node	*stackA;
	node	*stackB;
	/* min_max	a; */

	stackB = malloc(sizeof(node));
	stackB = NULL;
	/* stackB->data = "2312";
	stackB->nmbr = 2312; */
	stackA = ft_map_argvs(argc, argv);
	stackA = ft_validate_nmbr(stackA);
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

	/* ft_swap_sa(head); */
	/* ft_rotate(&head); */
	/* ft_push(&head, &stackB);
	ft_push(&head, &stackB); */
	/* ft_print_list(head); */
	/* printf("\n\n  %d  \n\n", head->count_m); */
	/* ft_print_list(stackB); */
	/* printf("\n\n");
	ft_print_list(stackB); */
	ft_get_next_line(&stackA, &stackB);
	/* while (stackA)
	{
		printf("the argv is %d: 		and the rank is: %d		and the bin is: %s\n", stackA->nmbr, stackA->rank, stackA->bin);
		stackA = stackA->next;
	} */
	while (stackA)
	{
		printf("the argv is %d: 		and the rank is: %d		and the bin is: %s\n", stackA->nmbr, stackA->order, stackA->bin);
		stackA = stackA->next;
	}
	return (0);
}
