#include <stdio.h>
#include "ft_list.h"
#include "ft_create_elem.c"

void	test(t_list **list);
void	test2(t_list *list);

int	main(void)
{
    t_list	*head;
    head = ft_create_elem("hello");
    printf("main: %p\n", head);
    test(&head);
    printf("%s\n", head->data);
    test2(head);
    printf("%s\n", head->data);
    return (0);
}

void	test(t_list **list)
{
	printf("test1: \n");
	printf("inside1: %p\n", list);
	printf("inside2: %p\n", &list);
	printf("inside3: %p\n", *list);
	(*list)->data = "test";
}

void	test2(t_list *list)
{
	printf("test2: \n");
	printf("inside1: %p\n", list);
	printf("inside2: %p\n", &list);
	list->data = "test2";
}
