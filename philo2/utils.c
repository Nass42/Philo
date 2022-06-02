/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:08:12 by namohamm          #+#    #+#             */
/*   Updated: 2022/06/02 16:21:23 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/****---------------------GET THE TIME-------------------****/
size_t ft_current_time()
{
	size_t time;
	struct timeval currrent;
	
	gettimeofday(&currrent, NULL);
	time = (currrent.tv_sec * 1000) + (currrent.tv_usec / 1000);
	return (time);
}
/****------------------------END--------------------------****/

/****---------------------ELAPSED TIME--------------------****/
size_t	ft_elapsed_time(size_t prev, size_t current)
{
	size_t	time;
	
	time = current - prev;
	return (time);
}
/****------------------------END--------------------------****/

/****---------------------ELAPSED TIME--------------------****/
void		ft_write_status(t_arg *arg, int id, char *string)
{
	pthread_mutex_lock(&(arg->mut_write));
	if (!(arg->dead))
	{
		printf("⏳ %zu ", ft_current_time() - arg->start_time);
		printf("%d ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(arg->mut_write));
	return ;
}
/****------------------------END--------------------------****/