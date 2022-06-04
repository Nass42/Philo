/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:23:09 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/04 15:42:54 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***---------------------TIME TO ENJOY------------------***/
void	philo_eats(t_philo *ph)
{
	t_arg *arg;

	arg = ph->arg;
	if (arg->feds)
		return ;
	if (!pthread_mutex_lock(&(arg->chopstick[ph->left_chopstick])) 
	&& !pthread_mutex_lock(&(arg->chopstick[ph->right_chopstick])))
	{
		if (arg->feds)
			return ;
		ft_write_status(arg, ph->id, "has taken a  fork  🥢");
		ft_write_status(arg, ph->id, "has taken a  fork  🥢");
	}
	if (arg->feds)
		return ;
	pthread_mutex_lock(&(arg->checking));
	ft_write_status(arg, ph->id, "is  eating  ...    🍔");
	ph->last_eat = ft_current_time();
	pthread_mutex_unlock(&(arg->checking));
	usleep(arg->eat * 1000);
	(ph->ate)++;
	pthread_mutex_unlock(&(arg->chopstick[ph->left_chopstick]));
	pthread_mutex_unlock(&(arg->chopstick[ph->right_chopstick]));
}
/***-------------END (EVERYTHING HAS AN END-----------***/

/***-------------------
 * CREATION OF THREADS
 ***/
void	*ft_philo_life(void *philo)
{
	int				i;
	t_philo	*ph;
	t_arg			*arg;

	i = 0;
	ph = (t_philo *)philo;
	arg = ph->arg;
	while (!(arg->dead) && !(arg->feds))
	{
		if (arg->feds)
			break ;
		philo_eats(philo);
		// usleep(arg->eat * 1000);
		if (arg->feds)
			break ;
		ft_write_status(arg, ph->id, "is  sleeping  ...  😴");
		usleep(arg->sleep * 1000);
		if (arg->feds)
			break ;
		ft_write_status(arg, ph->id, "is  thinking  ...  🧐");
		i++;
	}
	return (NULL);
}
/*
 * END
------------------*/
/***---------------------TIME TO ENJOY------------------***/
void	ft_wait_destroy(t_arg *arg, t_philo *ph)
{
	int i;

	i = 0;
	while (i < arg->philos)
	{
		pthread_join(ph[i].thread_id, NULL);
		i++;
	}
	i = 0;;
	while (i < arg->philos)
	{
		pthread_mutex_destroy(&(arg->chopstick[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->mut_write));
}
/***-------------END (EVERYTHING HAS AN END-----------***/
/***---------------------TIME TO ENJOY------------------***/
void	ft_death_feds(t_arg *arg, t_philo *ph)
{
	int i;

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
		while (arg->must_eat != -1 && i < arg->philos && ph[i].ate >= arg->must_eat)
			i++;
		if (i == arg->philos)
		{
			arg->feds = 1;
			printf("Everyone ate at least %d times 🦧\n", arg->must_eat);
		}
	}
}
/***-------------END (EVERYTHING HAS AN END-----------***/
/***----------------CREATION OF THREADS-----------------------***/
int		ft_threads(t_arg *arg)
{
	int				i;
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
		ph[i].last_eat = ft_current_time();
		i++;
	}
	ft_death_feds(arg, arg->ph);
	ft_wait_destroy(arg, ph);
	return (0);
}
/***-------------END (EVERYTHING HAS AN END-----------***/