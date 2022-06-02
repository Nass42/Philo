/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:27:15 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 11:24:57 by namohamm         ###   ########.fr       */
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
	return (time);
}
/****------------------------END--------------------------****/
void ft_write_status(int id, char *str, size_t time)
{
	printf("%ld Philo[%d] %s\n", time, id, str);
}
/****---------------------FT_GOOD_FOOD-------------------****/
void *ft_get_food(void *arg)
{
	t_arg	*ph;
	int		inc;
	int		id;
	size_t time;
	ph = (t_arg *)(arg);
	inc = ph->inc;
	ph->id = inc + 1;
		// pthread_mutex_lock(&(ph->mut_time_ms));
		time = compute_time() - ph->time_ms;
		// pthread_mutex_unlock(&(ph->mut_time_ms));
	while (1)
    {
		ft_write_status(ph->id, "hello", time);
		sleep(1);
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
	int		inc;
	size_t time;
	
	i = 0;
	while (i < (*arg)->philos)
	{
	(*arg)->time_ms = compute_time();
		//printf("the memory of args is %p\n", *arg);
		(*arg)->inc = i;
		// if (!pthread_create(&((*arg)->thread[i]), NULL,
		// 		ft_get_food, *arg))
		// 	printf("ERROR THREAD\n");
		//printf("Mahdy\n");
		pthread_create(&((*arg)->thread[i]), NULL, ft_get_food, *arg);
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