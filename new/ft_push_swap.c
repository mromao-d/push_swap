#include "ft_push_swap.h"

int	ft_validate_equal_args(int	argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (*argv && argv[i])
	{
		j = i + 1;
		while (*argv && argv[j])
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate_nmbr_args(int	argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

char *ft_binary(int nmbr)
{
	int		i;
	char	*output;

	output = malloc(sizeof(char) * 33);
	if (!output)
		return (0);
	i = 31;
	while (i >= 0)
	{
		if (((nmbr >> i) & 1) == 1)
			output[31 - i] = '1';
		else
			output[31 - i] = '0';
		i--;
	}
	output[32] = '\0';
	return (output);
}

// Uses Atoi -> change for libft function
s_node *ft_map_argvs(int argc, char *argv[])
{
	s_node	*head;
	s_node	*current;
	s_node	*prev;
	int		i;

	head = malloc(sizeof(*head));
	if (!head)
		return (0);
	i = 1;
	head->data = argv[i];
	head->bin = ft_binary(atoi(argv[i]));
	head->next = NULL;
	prev = head;
	while (++i < argc)
	{
		current = malloc(sizeof(*current));
		if (!current)
			return (0);
		current->data = argv[i];
		current->bin = ft_binary(atoi(argv[i]));
		current->next = NULL;
		prev->next = current;
		prev = current;
	}
	return (head);
}

void	ft_free_lst(s_node **head)
{
	s_node	*nxt;

	if (!head)
		return ;
	while (*head)
	{
		nxt = (*head)->next;
		/* if ((*head)->bin) */
		free((*head)->bin);
		free(*head);
		(*head) = nxt;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int		i;
	s_node	*head;
	s_node	*stackb;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = ft_validate_nmbr_args(argc, argv) + ft_validate_equal_args(argc, argv);
	if (i != 0)
	{
		write(1, "Error\n", 6);
		return (i);
	}
	head = ft_map_argvs(argc, argv);
	stackb = NULL;
	ft_rotate(&head, 'a');
	ft_push(&head, &stackb, 'b');
	ft_push(&stackb, &head, 'a');
	ft_print_list(head);
	/* ft_print_list(stackb); */
	/* ft_free_lst(&head); */
	return (0);
}
