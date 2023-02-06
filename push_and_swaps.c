#include "ft_push_swap.h"

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

Node	*ft_rotate(Node	*stack)
{
	Node	*temp;
	Node	*current;

	temp = malloc(sizeof(Node));
	temp->data = stack->data;
	temp->nmbr = stack->nmbr;
	temp->next = NULL;
	stack = stack->next;
	current = stack;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	return (stack);
}

/* void	ft_rotate_test(Node	*stack)
{
	Node	*temp;
	Node	*current;

	temp = malloc(sizeof(Node));
	temp->data = stack->data;
	temp->nmbr = stack->nmbr;
	temp->next = NULL;
	stack = stack->next;
	current = stack;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	return ;
} */

/* void	ft_push_swap(Node	*head_stack_A)
{
	Node	*stack_B;
	Node	*temp;

	stack_B = head_stack_A;
} */