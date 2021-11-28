#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*head;
	void	*tmp;
	int	size;
	int	i;
	int	j;

	head = begin_list;
	size = 0;
	i = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	while (i < size - 1)
	{
		head = begin_list;
		j = i;
		while (head && j < size - 1)
		{
			tmp = head->data;
			head->data = head->next->data;
			head->next->data = tmp;
			head = head->next;
			j++;
		}
		i++;
	}
}

