#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*head;
	t_list	*new;

	head = *begin_list;
	new = ft_create_elem(data);
	while (head->next)
	{
		if (cmp(head->data, data) >= 0 && head == *begin_list)
		{
			new->next = head;
			*begin_list = new;
			return ;
		}
		else if (cmp(head->data, data) < 0 && cmp(head->next->data, data) >= 0)
		{
			new->next = head->next;
			head->next = new;
			head->next = new;
			return ;	
		}
		head = head->next;
	}
	head->next = new;
}

/* or:
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_push_back(begin_list, data);
	list_sort(begin_list, cmp);
}
*/
