/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:56:38 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/23 18:07:40 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	printf("ft_printf: \n");
	ret = ft_printf("% d\n", -10);
	ft_printf("ret  %d\n", ret);
	printf("-----------------------------\n");
	printf("printf: \n");
	ret = printf("% d\n", -10);
	printf("ret  %x\n", ret);
	return (0);
}
