/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:16:19 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 11:21:58 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		add(int x, int y);
int		sub(int x, int y);
int		div(int x, int y);
int		mul(int x, int y);
int		mod(int x, int y);
int		do_op(int (*op)(int, int), int x, int y);
int		ft_atoi(char *str);
void	ft_puterr(char *err);
void	ft_putnbr(int nb);

#endif
