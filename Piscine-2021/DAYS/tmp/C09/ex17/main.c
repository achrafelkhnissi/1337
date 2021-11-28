#include <stdio.h>
#include <string.h>
#include "ft_sorted_list_merge.c"

void	print_list(t_list *head);
void	append_elem(t_list **head, void *data);

int	main(void)
{
	t_list	*list1;
	t_list	*list2;

	list1 = 0;
	list2 = 0;
	append_elem(&list1, "1");
	append_elem(&list1, "3");
	append_elem(&list1, "5");
	append_elem(&list1, "7");
	append_elem(&list2, "0");
	append_elem(&list2, "2");
	append_elem(&list2, "4");
	append_elem(&list2, "6");
	printf("List1: ");
	print_list(list1);
	printf("List2: ");
	print_list(list2);
	printf("\nAfter merge:\n");
	ft_sorted_list_merge(&list1, list2, strcmp);
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
		elem->next = ft_create_elem(data);
	}
	else
		*head = ft_create_elem(data);
}

t_list	*ft_create_elem(void *data)
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
