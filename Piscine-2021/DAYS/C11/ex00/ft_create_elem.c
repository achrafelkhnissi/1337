#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
    t_list	*new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}
