/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:27:15 by namohamm          #+#    #+#             */
/*   Updated: 2022/05/31 12:11:55 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/****---------------------FT_GOOD_FOOD-------------------****/
void time_to_eat(int ph)
{
	printf("Philo %d is eating 🤩\n", ph + 1);
}
/****---------------------FT_GOOD_FOOD-------------------****/
size_t compute_time()
{
	size_t time;
	struct timeval currrent_time;
	
	gettimeofday(&currrent_time, NULL);
	time = (currrent_time.tv_sec * 1000) + (currrent_time.tv_usec / 1000);
	// time = (currrent_time.tv_usec / 1000);
}
/****------------------------END--------------------------****/
/****---------------------FT_GOOD_FOOD-------------------****/
void *ft_get_food(void *arg)
{
	t_arg	*ph;
	int		inc;
	// int		res_lock;
	size_t time;
	size_t time2;
	// struct timeval currrent_time;
	// gettimeofday(&currrent_time, NULL);
	// time_stamp = currrent_time.tv_usec / 1000;
	time2 = compute_time();
	ph = (t_arg *)(arg);
	inc = ph->inc;

	while (1)
    {
		pthread_mutex_lock(&(ph->mut5));
		time = compute_time() - time2;
		pthread_mutex_unlock(&(ph->mut5));
	
    	if (!pthread_mutex_lock(&(ph->mutex[inc])) &&
    		 !pthread_mutex_lock(&(ph->mutex[(inc + 1) % ph->philos])))
		{
			pthread_mutex_lock(&(ph->mut1));
			printf("%ld %d has taken a fork\n", time, inc + 1);
			pthread_mutex_unlock(&(ph->mut1));
			// printf("%ld %d has taken a fork\n", time, inc + 1);
		}
		
			pthread_mutex_lock(&(ph->mut2));
		printf("%ld %d   is eating... 🍔\n", time, inc + 1);
			pthread_mutex_unlock(&(ph->mut2));
		usleep(ph->eat * 1000);
		// printf("eat = %d\n", ph->eat);
			pthread_mutex_lock(&(ph->mut3));
		printf("%ld %d is sleeping... 😴\n", time, inc + 1);
			pthread_mutex_unlock(&(ph->mut3));
		usleep(ph->sleep * 1000);
    	pthread_mutex_unlock(&(ph->mutex[(inc + 1) % ph->philos]));
    	pthread_mutex_unlock(&(ph->mutex[inc]));
	
			pthread_mutex_lock(&(ph->mut4));
		printf("%ld %d is thinking... 🤓\n", time, inc + 1);
			pthread_mutex_unlock(&(ph->mut4));
		pthread_mutex_unlock(&(ph->mut5));
			
		// pthread_exit(0);
	}
}
/****------------------------END--------------------------****/

/****----------------FT_MUTEX_DESTROY---------------------****/
int ft_mutex_destroy(t_arg **arg)
{
	int	i;

	i = 0;
	while (i < (*arg)->philos)
	{
		pthread_mutex_destroy(&((*arg)->mutex[i]));
		i++;
	}
	pthread_exit(0);
}
/****------------------------END--------------------------****/

/****---------------------FT_MUTEX_INIT-------------------****/
void ft_mutex_init(t_arg **arg)
{
	int	i;
	
	i = 0;
	// (*arg)->mutex[(*arg)->philos];
	while (i < (*arg)->philos)
	{
		pthread_mutex_init(&((*arg)->mutex[i]), NULL);
		i++;
	}
}
/****------------------------END--------------------------****/

/****---------------------FT_THREAD-----------------------****/
void ft_thread(t_arg **arg)
{
	int	i;

	i = 0;
	//(*arg)->inc = 12;
	while (i < (*arg)->philos)
	{
		//printf("the memory of args is %p\n", *arg);
		(*arg)->inc = i;
		// if (!pthread_create(&((*arg)->thread[i]), NULL,
		// 		ft_get_food, *arg))
		// 	printf("ERROR THREAD\n");
		//printf("Mahdy\n");
		pthread_create(&((*arg)->thread[i]), NULL, ft_philo_life, *arg);
		i++;
	}
}
/****------------------------END----------------------------****/
/****------------------FT_WAIT_THREAD-----------------------****/
void ft_wait_thread(t_arg **arg)
{
	int	i;

	i = 0;
	while (i < (*arg)->philos)
	{
		(*arg)->inc = i;
		// if (!pthread_join((*arg)->thread[i], NULL))
		// 	printf("ERROR WAIT\n");
		pthread_join((*arg)->thread[i], NULL);
		i++;
	}
}
/****------------------------END--------------------------****/