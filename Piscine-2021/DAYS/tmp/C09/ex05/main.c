#include <stdio.h>
#include "ft_list_push_params.c"

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*ptr;

	head = ft_list_push_params(ac, av);
	ptr = head;
	while(ptr)
	{
		printf("%s\n", ptr->data);
		ptr = ptr->next;
	}
	return (0);
}
