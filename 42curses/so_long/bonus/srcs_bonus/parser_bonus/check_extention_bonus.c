/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:47:26 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/10 14:59:51 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	check_extention(const char *src, const char *to_find)
{
	size_t	to_find_len;
	size_t	src_len;

	to_find_len = ft_strlen(to_find);
	src_len = ft_strlen(src);
	while (src_len > to_find_len)
	{
		src++;
		src_len--;
	}
	return (ft_strcmp(src, to_find));
}
