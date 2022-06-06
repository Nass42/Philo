/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:28:44 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/06 15:50:12 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define black "\033[0;30m"
# define red "\033[0;31m"
# define green "\033[0;32m"
# define yellow "\033[0;33m"
# define blue "\033[0;34m"
# define purple "\033[0;35m"
# define cyan "\033[0;36m"
# define white "\033[0;37m"

struct	s_arg;

typedef struct s_philo
{
	int					id;
	int					ate;
	int					left_chopstick;
	int					right_chopstick;
	long int			last_eat;
	pthread_t			thread_id;
	struct s_arg		*arg;
}						t_philo;

typedef struct s_arg
{
	int					philos;
	int					die;
	int					eat;
	int					sleep;
	int					must_eat;
	int					dead;
	int					feds;
	size_t				start_time;
	pthread_mutex_t		checking;
	pthread_mutex_t		mut_write;
	pthread_mutex_t		mut_eat;
	pthread_mutex_t		mut_read;
	pthread_mutex_t		mut_last_eat;
	pthread_mutex_t		mut_ate;
	pthread_mutex_t		chopstick[512];
	t_philo				ph[512];
}						t_arg;

int		ft_parse_init(int ac, char **av, t_arg *arg);
size_t	ft_current_time(void);
size_t	ft_elapsed_time(size_t prev, size_t current);
void	ft_write_status(t_arg *arg, int id, char *string);
int		ft_threads(t_arg *arg);
int		ft_atoi(const char *str);
void	philo_eats(t_philo *ph);
void	*ft_philo_life(void *philo);
void	ft_usleep(size_t time, t_arg *arg);
#endif