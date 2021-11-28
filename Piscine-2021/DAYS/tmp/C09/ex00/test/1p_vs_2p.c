#include <stdio.h>
#include "ft_list.h"

void	push1(t_list **begin_list, void *data);
t_list	*push2(t_list *begin_list, void *data);
void	print_list(t_list *list);

void	test_push1(void); // using double pointers.
void 	test_push2(void);  // using 1 pointer.

int	main(void)
{
	printf("test1: \n");
	test_push1();

	printf("\ntest2: \n");
	test_push2();
	return (0);
}

void	test_push1(void)
{
	t_list	*head;

	head = NULL;
	push1(&head, "double1");
	push1(&head, "double2");
	push1(&head, "double3");
	push1(&head, "double4");
	print_list(head);
}

void	test_push2(void)
{
	t_list	*head2;

	head2 = NULL;
	head2 = push2(head2, "!double1");
	head2 = push2(head2, "!double2");
	head2 = push2(head2, "!double3");
	head2 = push2(head2, "!double4");
	print_list(head2);
}

void	push1(t_list **begin_list, void *data)
{
	t_list *elem;

	if (*begin_list)
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*push2(t_list *begin_list, void *data)
{
	t_list	*node;

	node = begin_list;
	if (begin_list)
	{
		while(node->next != NULL)
			node = node->next;
		node->next = ft_create_elem(data);
	}
	else
		node = ft_create_elem(data);
	return (node);
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current != NULL)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}
