/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:55:18 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/07 00:55:19 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
