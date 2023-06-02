#include "ft_push_swap.h"

int	ft_validate_if_is_sorted(s_node **head)
{
	s_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->nmbr > tmp->next->nmbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_order_argvs(s_node *head)
{
	int		i;
	s_node	*tmp;

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

int	ft_check_has_one(s_node **head, int pos)
{
	s_node *tmp;
	int		i;

	tmp = *head;
	/* if (!tmp)
		return (-11); */
	i = 0;
	while (tmp)
	{
		if (tmp->bin[pos] == '0')
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_strlen(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_push_swap(s_node **stackA, s_node **stackB)
{
	int		i;
	int		pos;

	pos = ft_strlen((*stackA)->bin);
	printf("%d\n\n", ft_validate_if_is_sorted(stackA));
	while (ft_validate_if_is_sorted(stackA) != 0 && pos > -1)
	{
		i = 0;
		while (ft_check_has_one(stackA, pos) != 0)
		{
			if (((*stackA)->bin[pos]) == '0')
				ft_push(stackA, stackB, 'b');
			else
				ft_rotate(stackA, 'a');
			i++;
		}
		while (*stackB != NULL)
			ft_push(stackB, stackA, 'a');
		pos--;
		if (ft_validate_if_is_sorted(stackA) == 0)
			break;
		ft_order_argvs(*stackA);
	}
	printf("%d\n\n", ft_validate_if_is_sorted(stackA));
	return ;
}
