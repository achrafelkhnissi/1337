#include <stdio.h>
#include "ft_list_merge.c"

t_list	*create_elem(void *data);
void	print_list(t_list *head);
void	append_elem(t_list **head, void *data);

int	main(void)
{
	t_list	*list1;
	t_list	*list2;

	list1 = 0;
	list2 = 0;
	append_elem(&list1, "this");
	append_elem(&list1, "is");
	append_elem(&list1, "list1");
	append_elem(&list2, "this");
	append_elem(&list2, "is");
	append_elem(&list2, "list2");
	print_list(list1);
	printf("\nAfter merge:\n");
	ft_list_merge(&list1, &list2);
	print_list(list1);
	return (0);
}

void	append_elem(t_list **head, void *data)
{
	t_list	*elem;

	if (*head)
	{
		elem = *head;
		while (elem->next)
			elem = elem->next;
		elem->next = create_elem(data);
	}
	else
		*head = create_elem(data);
}

t_list	*create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s ", head->data);
		head = head->next;
	}
	putchar('\n');
}
