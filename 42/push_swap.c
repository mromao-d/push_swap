/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:11:23 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/07 18:56:34 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


node	*ft_validate_nmbr(node *head)
{
	node	*current;
	node	*error;

	error = malloc(sizeof(*error));
	if (!error)
		return (NULL);
	error->data = "The validation with Atoi says Fuck You!";
	error->next = NULL;
	current = head; 
	while (current)
	{
		current->data = ft_atoi_for_validation(current->data);
		if (ft_strcmp(current->data, "Atoi says Fuck you") == 0)
		{	
			printf("Error");
			return (0);
		}
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
		return (NULL);
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

int	ft_validate_argvs(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 2)
		return (1);
	i = 1;
	while (argv[i])
	{

		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (2);
			j++;
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

node	*ft_map_argvs(int argc, char *argv[])
{
	node	*temp;
	node	*current;
	node	*head;
	int		i;

	if (argc < 2)
		return (0);
	if (ft_validate_argvs(argc, argv) != 0)
	{
		printf("Error\n");
		return (NULL);
	}
	head = (node *) malloc(sizeof(*head));
	if (!head)
		return(NULL);
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
		temp = malloc(sizeof(*temp));
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



void	ft_push_swap(node **stackA, node **stackB)
{
	node	*tmp;
	node	*tmpb;
	int		i;
	int		pos;
	int		val;
	int		aux;

	tmp = *stackA;
	pos = 31;
	aux = 0;
	val = ft_validate_if_is_sorted(stackA);
	printf("%d\n", ft_validate_if_is_sorted(stackA));
	while (val != 1 && pos > -1)
	{
		i = 0;
		tmp = *stackA;
		if (!tmp)
			return ;
		while (tmp)
		{
			((tmp->bin)[pos] == '0') ? ft_push(stackA, stackB, i, 'b') : 0;
			i++;
			tmp = tmp->next;
			printf("rb\n");
		}
		tmpb = *stackB;
		if (!tmpb)
			return ;
		while (tmpb)
		{
			ft_push_simple(stackB, stackA, 'a');
			tmpb = tmpb->next;
			printf("ra\n");
		}
		pos--;
		if (ft_validate_if_is_sorted(stackA) == 1)
			break;
		ft_order_argvs(*stackA);
	}
	printf("%d\n", ft_validate_if_is_sorted(stackA));
	return ;
}

int	main(int argc, char *argv[])
{
	node	*stackA;
	node	*stackB;
	
	if (argc < 2)
		return (0);
	stackA = NULL;
	stackB = NULL;
	stackA = ft_map_argvs(argc, argv);
	if (ft_strcmp(stackA->data, "Error") == 0)
		return (0);
	ft_push_swap(&stackA, &stackB);
	/* ft_push_swap(&stackA, &stackB); */
	/* while (stackA)
	{
		printf("the argvA is %d: 		and the rank is: %d		and the bin is: %s		and the order is: %d\n", stackA->nmbr, stackA->rank, stackA->bin, stackA->order);
		stackA = stackA->next;
	} */
	/* printf("\n\n"); */
	ft_free_lst(&stackA);
	/* ft_free_lst(&stackB); */
	return (0);
}
