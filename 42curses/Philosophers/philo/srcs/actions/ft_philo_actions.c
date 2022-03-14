/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:18:25 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/07 04:18:43 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	while (!philo->should_die && !philo->info->finish)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->info->number_of_philosophers;
		grab_fork(philo, right_fork);
		if (philo->info->number_of_philosophers == 1)
		{
			usleep(1000000);
			break ;
		}
		grab_fork(philo, left_fork);
		ft_eating(philo);
		down_fork(philo, right_fork, left_fork);
		sleep_then_think(philo);
	}
	return (NULL);
}
