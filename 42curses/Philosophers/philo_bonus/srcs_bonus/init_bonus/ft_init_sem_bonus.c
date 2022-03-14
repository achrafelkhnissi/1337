/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:59:59 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/13 05:01:04 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*0644
0 > no access to file
6 > read/write permisson for the user
4 > read only for the group and others
*/
int	ft_init_sem(t_info *info)
{
	info->forks = sem_open("sem", O_CREAT | O_EXCL, 0644,
			info->number_of_philosophers);
	if (info->forks == SEM_FAILED || sem_unlink("sem"))
		ft_puterr("ft_init_sem:12 - error initializing semaphore\n");
	return (FT_SUCCESS);
}
