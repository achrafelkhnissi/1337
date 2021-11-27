#include <stdio.h>
#include "ft_list.h"
#include "ft_list_clear.c"

t_list	*create_elem(void *data);
void	print_list(t_list *head);
void	append_elem(t_list **head, void *data);
t_list	*push_params(int ac, char **av);

int	main(int ac, char **av)
{
	t_list	*head;

	head = push_params(ac, av);
	print_list(head);
	printf("\nAfter clear: \n");
	ft_list_clear(&head);
	print_list(head);
	return (0);
}

t_list	*push_params(int ac, char **av)
{
	t_list	*elem;
	int	i;

	elem = 0;
	i = 1;
	while (i < ac)
		append_elem(&elem, av[i++]);
	return (elem);
}

void	append_elem(t_list **head, void *data)
{
	t_list	*elem;

	elem = 0;
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
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", head->data);
		head = head->next;
	}
}
