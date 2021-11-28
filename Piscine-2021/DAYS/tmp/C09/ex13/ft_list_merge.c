#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2)
{
	t_list	*head;

	head = *begin_list1;
	while (head->next)
		head = head->next;
	head->next = *begin_list2;
}
