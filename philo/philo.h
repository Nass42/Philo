/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:58:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/31 12:12:19 by namohamm         ###   ########.fr       */
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
	pthread_t	thread[10];
	pthread_mutex_t	mutex[10];
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	time_die;
	int	time_meat;
	pthread_mutex_t	mut1;
	pthread_mutex_t	mut2;
	pthread_mutex_t	mut3;
	pthread_mutex_t	mut4;
	pthread_mutex_t	mut5;
	int inc;
	
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