#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *begin_list;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr;
		free(ptr);
		ptr = tmp->next;
	}
	*begin_list = NULL;
}
