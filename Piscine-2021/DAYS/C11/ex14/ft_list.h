/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:57:29 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:57:30 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void		*data;
}			t_list;

t_list *ft_create_elem(void *data);

#endif
