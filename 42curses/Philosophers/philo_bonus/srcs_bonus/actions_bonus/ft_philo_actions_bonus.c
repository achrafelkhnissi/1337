/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:02:28 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/13 05:02:48 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (true)
	{
		if ((philo->last_meal + philo->info->time_to_die) < ft_get_time())
		{
			ft_print_msg(philo, "died");
			exit(FT_FAILURE);
		}
		usleep(1000);
	}
	return (NULL);
}

void	ft_philo_actions(t_philo *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, ft_check_death, philo);
	while (true)
	{
		ft_grab_fork(philo);
		ft_grab_fork(philo);
		ft_eating(philo);
		ft_down_forks(philo);
		ft_sleep_then_think(philo);
	}
	pthread_join(monitor, NULL);
}
