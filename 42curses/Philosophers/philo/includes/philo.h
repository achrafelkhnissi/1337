/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:05:14 by ael-khni          #+#    #+#             */
/*   Updated: 2022/03/07 04:39:38 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FT_SUCCESS 0
# define FT_FAILURE 1

enum e_bool
{
	false,
	true
};

typedef struct timeval	t_time;
typedef struct s_info	t_info;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			should_die;
	long long	last_meal;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_lock;
}	t_info;

/* UTILS FUNCTIONS */
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_puterr(char *err);
void		*ft_calloc(size_t count, size_t size);
long long	ft_current_time(t_philo *philo);
long long	ft_get_time(void);

/* INIT FUNCTIONS */
int			ft_check_info(t_info info, int ac);
int			ft_init_all(t_info *info, int ac, char **av);
void		ft_init_mutex(t_info *info);
void		ft_create_philos(t_info *info);
void		ft_get_args(t_info *info, int ac, char **av);

/* ACT FUNCTIONS */
void		down_fork(t_philo *philo, int f1, int f2);
void		grab_fork(t_philo *philo, int f);
void		ft_join_free(t_info *info);
void		*philosophers(void *arg);
void		ft_print_msg(t_philo *philo, char *msg);
void		ft_eating(t_philo *philo);
void		sleep_then_think(t_philo *philo);

#endif
