/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_msg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:02:56 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/13 05:02:59 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_msg(t_philo *philo, char *msg)
{
	if (!philo->should_die)
		printf("%lli\t%i\t%s\n", ft_current_time(philo), philo->id + 1, msg);
}
