/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:56:38 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/26 18:24:19 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int test = 100;
	int	ret;
	printf("ft_printf: \n");
	ret = ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
	ft_printf("ret  %d\n", ret);
	printf("-----------------------------\n");
	printf("printf: \n");
	ret = printf("%p %p\n", LONG_MIN, LONG_MAX);
	printf("ret  %d\n", ret);
	return (0);
}

