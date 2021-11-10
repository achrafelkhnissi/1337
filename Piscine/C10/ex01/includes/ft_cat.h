/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:52:47 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/10 10:29:23 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

#include <fcntl.h>
#include <libgen.h>
#include <sys/errno.h>
#include <stdio.h>
#include <unistd.h>

void	in_to_out(void);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_cat(char *file_name);

#endif
