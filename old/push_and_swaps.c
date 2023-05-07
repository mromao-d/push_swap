#include "ft_push_swap.h"

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

void	ft_add_move(node **head)
{
	node	*tmp;

	if (!head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp->count_m += 1;
		tmp = tmp->next;
	}
	return ;
}

void	ft_swap_sa(node *head)
{
	char	*second;
	char	*temp;
	int		one;
	int		two;

	if (ft_count_nodes(head) < 2)
		return ;
	/* head->count_m += 1; */
	temp = head->data;
	one = head->nmbr;
	second = head->next->data;
	two = head->next->nmbr;
	head->data = second;
	head->nmbr = two;
	head->next->data = temp;
	head->next->nmbr = one;
	ft_add_move(&head);
	return ; 
}

/* Push the first element of stack A and put it on top of stack B */
void	ft_swap_both_stacks(node *stackA, node *stackB)
{
	/* stackA->count_m += 2; */
	ft_swap_sa(stackA);
	ft_swap_sa(stackB);
	ft_add_move(&stackA);
	ft_add_move(&stackA);
}

void	ft_push_test(node *stackA, node *stackB)
{
	if (!stackA || !stackB)
		return ;
	stackB->next = stackA;
	stackA = stackB;
	ft_add_move(&stackA);
}

node	*ft_copy_node(node	*head)
{
	node	*copy;

	copy = (node *)malloc(sizeof(node));
	copy->data = head->data;
	copy->nmbr = head->nmbr;
	copy->rank = head->rank;
	copy->next = NULL;
	copy->count_m = head->count_m;
	copy->bin = head->bin;
	return (copy);
}

void	ft_add_first_node(node **head, node	*copy)
{
	copy->next = *head;
	copy->count_m = (*head)->count_m;
	*head = copy;
	return ;
}

void	ft_push(node **stackA, node **stackB)
{
	node	*tmp;

	tmp = *stackA;
	if (!tmp)
		return ;
	/* (*stackA)->count_m++; */
	if (!*stackB)
		*stackB = ft_copy_node(*stackA);
	else
		ft_add_first_node(stackB, ft_copy_node(*stackA));
	*stackA = (*stackA)->next;
	ft_add_move(stackA);
	ft_add_move(stackB);
	tmp->next = NULL;
	free(tmp);
	return ;
}

void	ft_rotate(node	**stack)
{
	node	*temp;
	node	*first;
	node	*travel;

	temp = *stack;
	/* (*stack)->count_m++; */
	first = ft_copy_node(*stack);
	temp = temp->next;
	*stack = temp;
	travel = *stack;
	while (travel->next != NULL)
		travel = travel->next;
	travel->next = first;
	ft_add_move(stack);
	return ;
}

void	ft_reverse_rotate(node **stack)
{
	node	*last;
	node	*temp;

	temp = *stack;
	/* (*stack)->count_m++; */
	while (temp->next->next != NULL)
		temp = temp->next;
	last = ft_copy_node(temp->next);
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_add_move(stack);
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
