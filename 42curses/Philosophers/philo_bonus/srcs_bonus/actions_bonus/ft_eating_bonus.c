/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:01:32 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/13 05:01:42 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eating(t_philo *philo)
{
	philo->last_meal = ft_get_time();
	ft_print_msg(philo, "is eating");
	usleep(philo->info->time_to_eat * 1000);
}
