/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:43:46 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/31 13:44:51 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_write_status(char *str, void *arg)
{
	long int		time;
	t_arg	*ph;
	int		inc;
	
	ph = (t_arg *)(arg);
	printf("eat = %d\n", ph->eat);
	inc = ph->inc;
	time = compute_time();
	if (time >= 0 && time <= 2147483647)
	{
		printf("%ld ", time);
		printf("Philo[%d] %s", ph->inc, str);
	}
}

/******----------THE WAY OF LIFE OF A PHILOSOPHER-----------******/
void *ft_philo_life(void *arg)
{
	t_arg	*ph;
	int		inc;
	
	ph = (t_arg *)(arg);
	inc = ph->inc;
	while(1)
	{
		pthread_mutex_lock(&(ph->mutex[inc]));
		pthread_mutex_lock(&(ph->write_mutex));
		ft_write_status("has taken a fork\n", &arg);
		pthread_mutex_unlock(&(ph->write_mutex));
		if (!&(ph->mutex[(inc + 1) % ph->philos]))
		{
			usleep(ph->die);
			break; ;
		}
		pthread_mutex_lock(&(ph->mutex[(inc + 1) % ph->philos]));
		pthread_mutex_lock(&(ph->write_mutex));
		ft_write_status("has taken a fork\n", &arg);
		pthread_mutex_unlock(&(ph->write_mutex));
		pthread_mutex_lock(&(ph->write_mutex));
		ft_write_status("is eating\n", &arg);
		pthread_mutex_lock(&(ph->time_eat));
		ph->time_meat = compute_time();
		pthread_mutex_unlock(&(ph->time_eat));
		pthread_mutex_unlock(&(ph->write_mutex));
		usleep(ph->eat * 1000);
		pthread_mutex_unlock(&(ph->mutex[(inc + 1) % ph->philos]));
		pthread_mutex_unlock(&(ph->mutex[inc]));
		pthread_mutex_lock(&(ph->write_mutex));
		ft_write_status("is sleeping\n", &arg);
		pthread_mutex_unlock(&(ph->write_mutex));
		usleep(ph->sleep * 1000);
		pthread_mutex_lock(&(ph->write_mutex));
		ft_write_status("is thinking\n", &arg);
		pthread_mutex_unlock(&(ph->write_mutex));
	}
}
/*-------------------------END-----------------------------------*/