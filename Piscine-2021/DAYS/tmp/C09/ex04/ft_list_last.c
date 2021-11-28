#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	//t_list	*last;

	//last = begin_list;
	if (!begin_list)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
