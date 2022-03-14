/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:03:58 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/13 05:26:43 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define FT_SUCCESS 0
# define FT_FAILURE 1

typedef long long		t_loong;
typedef struct timeval	t_time;
typedef struct s_info	t_info;

enum e_bool
{
	false,
	true
};

typedef struct s_philo
{
	int		id;
	int		ate;
	int		should_die;
	t_loong	last_meal;
	t_info	*info;
}	t_philo;

typedef struct s_info
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_philosophers;
	int		number_of_times_each_philosopher_must_eat;
	int		*id_table;
	t_loong	creation_time;
	sem_t	*forks;
}	t_info;

/* INIT */
void	ft_get_args(t_info *info, int ac, char **av);
void	ft_create_philos(t_info *info);
void	ft_free_all(t_info *info);
int		ft_init_sem(t_info *info);

/* ACT */
void	ft_print_msg(t_philo *philo, char *msg);
void	ft_philo_actions(t_philo *philo);
void	ft_grab_fork(t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_down_forks(t_philo *philo);
void	ft_sleep_then_think(t_philo *philo);

/* UTILS */
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_puterr(char *err);
void	*ft_calloc(size_t count, size_t size);
t_loong	ft_current_time(t_philo *philo);
t_loong	ft_get_time(void);

#endif // PHILO_BONUS_H
