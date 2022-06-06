/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:51:31 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/06 16:57:55 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***---------------------TIME TO ENJOY------------------***/
void	philo_eats(t_philo *ph)
{
	t_arg	*arg;

	arg = ph->arg;
	if (ph->id % 2) {
		if (!pthread_mutex_lock(&(arg->chopstick[ph->left_chopstick]))
		&& !pthread_mutex_lock(&(arg->chopstick[ph->right_chopstick])))
		{
			ft_write_status(arg, ph->id, "has taken a  fork  🥢");
			ft_write_status(arg, ph->id, "has taken a  fork  🥢");
		}
	} else {
		if (!pthread_mutex_lock(&(arg->chopstick[ph->right_chopstick]))
		&& !pthread_mutex_lock(&(arg->chopstick[ph->left_chopstick])))
	{
		ft_write_status(arg, ph->id, "has taken a  fork  🥢");
		ft_write_status(arg, ph->id, "has taken a  fork  🥢");
	}
	}
	// if (!pthread_mutex_lock(&(arg->chopstick[ph->left_chopstick]))
	// 	&& !pthread_mutex_lock(&(arg->chopstick[ph->right_chopstick])))
	// {
	// 	ft_write_status(arg, ph->id, "has taken a  fork  🥢");
	// 	ft_write_status(arg, ph->id, "has taken a  fork  🥢");
	// }
	pthread_mutex_lock(&(arg->checking));
	ft_write_status(arg, ph->id, "is  eating  ...    🍔");
	pthread_mutex_lock(&(arg->mut_last_eat));
	ph->last_eat = ft_current_time();
	pthread_mutex_unlock(&(arg->mut_last_eat));
	pthread_mutex_unlock(&(arg->checking));
	// usleep(arg->eat);
	ft_usleep(arg->eat, arg);
	pthread_mutex_lock(&(arg->mut_ate));
	(ph->ate)++;
	pthread_mutex_unlock(&(arg->mut_ate));
	pthread_mutex_unlock(&(arg->chopstick[ph->right_chopstick]));
	pthread_mutex_unlock(&(arg->chopstick[ph->left_chopstick]));
}
/***-------------END (EVERYTHING HAS AN END-----------***/

/***-------------------
 * CREATION OF THREADS
 ***/
void	*ft_philo_life(void *philo)
{
	int		i;
	t_philo	*ph;
	t_arg	*arg;

	i = 0;
	ph = (t_philo *)philo;
	arg = ph->arg;
	if (ph->id % 2)
		usleep(20000);
	while (!(arg->dead))
	{
		philo_eats(philo);
		// usleep(arg->eat * 1000);
		
		pthread_mutex_lock(&(arg->mut_read));
		if (arg->feds)
		{
			pthread_mutex_unlock(&(arg->mut_read));
			break;
		}
		pthread_mutex_unlock(&(arg->mut_read));
		
		ft_write_status(arg, ph->id, "is  sleeping  ...  😴");
		// usleep(arg->sleep);
		ft_usleep(arg->sleep, arg);
		ft_write_status(arg, ph->id, "is  thinking  ...  🧐");
		i++;
	}
	return (NULL);
}
/*
 * END
------------------*/
