#include <stdio.h>
#include "ft_list.h"
#include "ft_list_push_back.c"

void	print_list(t_list *list);

int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_list_push_back(&head, "hello!");
	ft_list_push_back(&head, "world!");
	print_list(head);
	return (0);
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
