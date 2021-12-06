/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:53:47 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:53:49 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
