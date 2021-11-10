/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:42:38 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 11:20:11 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

int	do_operations(char op, int *result, int x, int y)
{
	if (op == '+')
		*result = do_op(add, x, y);
	if (op == '-')
		*result = do_op(sub, x, y);
	if (op == '/')
		*result = do_op(div, x, y);
	if (op == '*')
		*result = do_op(mul, x, y);
	if (op == '%')
		*result = do_op(mod, x, y);
	return (*result);
}

int	main(int ac, char **av)
{
	int		x;
	int		y;
	int		result;
	char	op;

	if (ac == 4)
	{
		x = ft_atoi(av[1]);
		op = *av[2];
		y = ft_atoi(av[3]);
		if (y == 0 && op == '/')
		{
			ft_puterr("Stop : division by zero\n");
			return (-1);
		}
		if (y == 0 && op == '%')
		{
			ft_puterr("Stop : modulo by zero\n");
			return (-1);
		}
		result = do_operations(op, &result, x, y);
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	return (0);
}
