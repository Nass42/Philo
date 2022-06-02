/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:28:44 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 14:24:32 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct s_arg;

typedef	struct			s_philo
{
	int					id;
	int					ate;
	int					left_chopstick;
	int					right_chopstick;
	long int			last_eat;
	pthread_t			thread_id;
	struct s_arg		*arg;
}						t_philo;

typedef struct			s_arg
{
	int					philos;
	int					die;
	int					eat;
	int					sleep;
	int					must_eat;
	int					dead;
	int					well_fed;
	size_t				start_time;
	pthread_mutex_t		checking;
	pthread_mutex_t		mut_write;
	pthread_mutex_t		chopstick[512];
	t_philo				philo[512];
}						t_arg;


int	ft_parse_init(int ac, char **av, t_arg *arg);

#endif