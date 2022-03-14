/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:21:36 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/07 04:21:44 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->finish_lock, NULL);
	while (i < info->number_of_philosophers)
		pthread_mutex_init(&info->forks[i++], NULL);
}
