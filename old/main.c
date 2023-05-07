int main(int argc, char *argv[])
{
	printf("\n\n asds%d \n\n", ft_atoi_adapted("42"));
}


int	main(int argc, char *argv[])
{
	node	*head;
	node	*stackB;
	/* min_max	a; */

	stackB = malloc(sizeof(node));
	stackB = NULL;
	/* stackB->data = "2312";
	stackB->nmbr = 2312; */
	head = ft_map_argvs(argc, argv);
	/* head = ft_validate_nmbr(head); */
	/* a = ft_save_min_max(head);
	printf("\n\n %d \n\n", a.min); */
	/* ft_swap_sa(head); */
	/* ft_sort_shit(head); */
	/* ft_push_test(head, stackB, head); */
	/* head = ft_rotate(head); */
	/* printf("\nthe value is: %d \n\n", ft_find_max(head)); */
	/* ft_reverse_rotate(&head); */
	printf("\n\n asds%d \n\n", ft_atoi_adapted("42"));
	if (argc == 3)
		ft_sort_2_digits(&head, argc, *argv);
	else if (argc == 4)
		ft_sort_3_digits(&head, argc);
	else if (argc == 6)
		ft_sort_5_digits(&head, &stackB, argc, *argv);
	/* ft_swap_sa(head); */
	/* ft_rotate(&head); */
	/* ft_push(&head, &stackB);
	ft_push(&head, &stackB); */
	ft_print_list(head);
	/* ft_print_list(stackB); */
	/* printf("\n\n");
	ft_print_list(stackB); */
	return (0);
}
