/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:58:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 10:17:07 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_arg
{
	int	philos;
	int	die;
	int	eat;
	int	sleep;
	int	m_eat;
	pthread_t		thread[512];
	pthread_mutex_t	mutex[512];
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	mut_eat;
	pthread_mutex_t	mut_die;
	pthread_mutex_t	mut_sleep;
	pthread_mutex_t	mut_time_ms;
	int	time_meat;
	int inc;
	int	id;
	size_t	time_ms;
	
}		t_arg;


int	ft_parse(int ac, char **av, t_arg **arg);
void *ft_get_food(void *arg);
int ft_mutex_destroy(t_arg **arg);
void ft_mutex_init(t_arg **arg);
void ft_thread(t_arg **arg);
void ft_wait_thread(t_arg **arg);
size_t compute_time();
void *ft_philo_life(void *arg);

#endif