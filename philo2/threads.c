/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:23:09 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/06 17:04:37 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***---------------------TIME TO ENJOY------------------***/
void	ft_wait_destroy(t_arg *arg, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < arg->philos)
	{
		pthread_join(ph[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < arg->philos)
	{
		pthread_mutex_destroy(&(arg->chopstick[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->mut_write));
}
/***-------------END (EVERYTHING HAS AN END-----------***/

void	check_feds(int i, t_arg *arg)
{
	if (i == arg->philos)
	{
		pthread_mutex_lock(&(arg->mut_read));
		arg->feds = 1;
		pthread_mutex_unlock(&(arg->mut_read));
		// printf("Everyone ate at least %d times 🦧\n", arg->must_eat);
	}
}

/***---------------------TIME TO DIE------------------***/
void	ft_death_feds(t_arg *arg, t_philo *ph)
{
	int	i;

	while (!(arg->feds))
	{
		i = 0;
		while (i < arg->philos && !(arg->dead))
		{
			pthread_mutex_lock(&(arg->checking));
			if (ft_elapsed_time(ph[i].last_eat, ft_current_time()) > arg->die)
			{
				ft_write_status(arg, i, "died 💀");
				arg->dead = 1;
			}
			pthread_mutex_unlock(&(arg->checking));
			usleep(100);
			i++;
		}
		if (arg->dead)
			break ;
		i = 0;
		pthread_mutex_lock(&(arg->mut_ate));
		while (arg->must_eat != -1 && i < arg->philos
			&& ph[i].ate >= arg->must_eat)
			i++;
		pthread_mutex_unlock(&(arg->mut_ate));
		check_feds(i, arg);
	}
}
/***-------------END (EVERYTHING HAS AN END-----------***/

/***----------------CREATION OF THREADS-----------------------***/
int	ft_threads(t_arg *arg)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = arg->ph;
	if (arg->philos == 1)
	{
		printf("⏳ 0 1 died 💀\n");
		return (0);
	}
	arg->start_time = ft_current_time();
	while (i < arg->philos)
	{
		pthread_create(&(ph[i].thread_id), NULL, ft_philo_life, &(ph[i]));
		pthread_mutex_lock(&(arg->mut_last_eat));
		ph[i].last_eat = ft_current_time();
		pthread_mutex_unlock(&(arg->mut_last_eat));
		i++;
	}
	ft_death_feds(arg, arg->ph);
	ft_wait_destroy(arg, ph);
	return (0);
}
/***-------------END (EVERYTHING HAS AN END-----------***/