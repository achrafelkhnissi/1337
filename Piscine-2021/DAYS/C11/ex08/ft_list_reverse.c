#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*head;
	t_list	*prev;
	t_list	*next;

	head = *begin_list;
	prev = NULL;
	next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	*begin_list = prev;
}
