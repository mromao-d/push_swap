#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char		*data;
	struct node	*next;
} Node;

void	ft_print_list(Node *head) 
{
	Node	*current;
	
	current = head;
	while (current)
	{
		printf("%s \n", current->data);
		current = current->next;
	}
}

Node	*ft_map_argvs(int argc, char *argv[])
{
	Node	*temp;
	Node	*current;
	Node	*head;
	int		i;

	head = malloc(sizeof(Node));
	head->data = argv[1];
	head->next = NULL;
	current = head;
	i = 1;
	current = head;
	while (++i < argc)
	{
		temp = malloc(sizeof(Node));
		temp->data = argv[i];
		temp->next = NULL;
		current->next = temp;
		current = temp;
	}
	return (head);
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

Node	*ft_swap_sa(Node *head)
{
	char	*second;
	char	*temp;

	if (ft_count_nodes(head) < 2)
		return (head);
	temp = head->data;
	second = head->next->data;
	head->data = second;
	head->next->data = temp;
	return (head);
}

char	*ft_atoi_adapted(char	*str)
{
	int	n;
	int	nb;
	int	i;

	i = 0;
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

Node	*ft_validate_nmbr(Node *head)
{
	Node	*current;
	Node	*error;

	error = malloc(sizeof(error));
	error->data = "The validation with Atoi says Fuck You!";
	error->next = NULL;
	current = head; 
	while (current)
	{
		current->data = ft_atoi_adapted(current->data);
		if (strcmp(current->data, "Atoi says Fuck you") == 0)
			return (error);
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
	ft_print_list(head);
	return (0);
}