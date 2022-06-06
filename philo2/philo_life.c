/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:51:31 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/05 17:51:34 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***---------------------TIME TO ENJOY------------------***/
void	philo_eats(t_philo *ph)
{
	t_arg	*arg;

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
	// usleep(arg->eat);
	ft_usleep(arg->eat, arg);
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
	int		i;
	t_philo	*ph;
	t_arg	*arg;

	i = 0;
	ph = (t_philo *)philo;
	arg = ph->arg;
	if (ph->id % 2)
		usleep(20000);
	while (!(arg->dead) && !(arg->feds))
	{
		philo_eats(philo);
		// usleep(arg->eat * 1000);
		if (arg->feds)
			break ;
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
