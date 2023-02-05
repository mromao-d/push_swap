#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char		*data;
	int			nmbr;
	struct node	*next;
} Node;

/* int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} */

void	ft_print_list(Node *head) 
{
	Node	*current;
	
	current = head;
	if (strcmp(current->data, "The validation with Atoi says Fuck You!") == 0)
	{	
		printf("%s \n", current->data);
		return ;
	}
	while (current)
	{
		printf("%i \n", current->nmbr);
		current = current->next;
	}
	return ;
}

int	ft_count_nodes(Node *head)
{
	int		i;
	Node	*current;

	i = 0;
	current = head;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_swap_sa(Node *head)
{
	char	*second;
	char	*temp;
	int		one;
	int		two;

	if (ft_count_nodes(head) < 2)
		return ;
	temp = head->data;
	one = head->nmbr;
	second = head->next->data;
	two = head->next->nmbr;
	head->data = second;
	head->nmbr = two;
	head->next->data = temp;
	head->next->nmbr = one;
	return ; 
}

char	*ft_atoi_for_validation(char	*str)
{
	int	n;
	int	nb;
	int	i;

	i = -1;
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

	i = -1;
	while (str[++i])
	{
		n = str[i] - 48;
		nb = nb * 10 + n;
	}
	return(nb);
}

Node	*ft_validate_nmbr(Node *head)
{
	Node	*current;
	Node	*error;

	error = malloc(sizeof(Node));
	error->data = "The validation with Atoi says Fuck You!";
	error->next = NULL;
	current = head; 
	while (current)
	{
		current->data = ft_atoi_for_validation(current->data);
		if (strcmp(current->data, "Atoi says Fuck you") == 0)
			return (error);
		current = current->next;
	}
	return (head);
}

Node	*ft_map_argvs(int argc, char *argv[])
{
	Node	*temp;
	Node	*current;
	Node	*head;
	int		i;

	head = malloc(sizeof(Node));
	head->data = argv[1];
	head->nmbr = ft_atoi_adapted(argv[1]);
	head->next = NULL;
	current = head;
	i = 1;
	current = head;
	while (++i < argc)
	{
		temp = malloc(sizeof(Node));
		temp->data = argv[i];
		temp->nmbr = ft_atoi_adapted(argv[i]);
		temp->next = NULL;
		current->next = temp;
		current = temp;
	}
	return (head);
}

/* int	*ft_store_argvs_as_array(Node *)
{
	int	i;

	i = -1;
} */
Node	*ft_sort_shit(Node *head)
{
	Node	*current;
	
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
	return (head);
}

int	main(int argc, char *argv[])
{
	Node	*head;

	head = ft_map_argvs(argc, argv);
	head = ft_validate_nmbr(head);
	ft_swap_sa(head);
	head = ft_sort_shit(head);
	ft_print_list(head);
	return (0);
}